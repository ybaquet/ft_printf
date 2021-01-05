#include "../ft_printf.h"

#include <stdio.h>
int get_attr_value(char *s, va_list ap, int to_free)
{
	int		value;
//	char	*pt;

	if (!s || !*s)
		return (0);
	else if ('*' == s[0])
		return(va_arg(ap, int));
	else
	{
//		pt = s;
//		while (*pt)
//		{
//			if (*pt < '0' || *pt > '9')
//				break;
//			pt++;
//		}
//		*pt = 0;
		value  = ft_atoi(s);
	}
	if (to_free)
		free_s(s);
	return (value);
}

void set_attr(t_arg *arg, va_list ap)
{
	int		pos;
	char	*pt;
	char	*wstr;

	pt = arg->format;
	arg->left = 0;
	if ('-' == *pt)
	{
		arg->left = 1;
		pt++;
	}
	pos = index_of(pt, '.');
	if (-1 == pos)
	{
		arg->length = get_attr_value(pt , ap, 0);
		arg->precis = -1;
	}
	else
	{
		wstr = ft_substr(pt, 0, pos);
		arg->length = get_attr_value(wstr, ap, 1);
		wstr = ft_substr(pt, pos + 1, ft_strlen(pt) - pos + 1);
		arg->precis = get_attr_value(wstr, ap, 1);
	}
}

void get_conv(va_list ap, const char *fmt, int *start, t_arg *arg)
{
	int i;

	i = 0;
	fmt = fmt + *start;
	if (*fmt)
	{
		fmt++;
		while (*fmt && 'c' != *fmt && 's' != *fmt && 'p' != *fmt && 'd' != *fmt
				&& 'i' != *fmt && 'u' != *fmt && 'x' != *fmt && 'X' != *fmt
				&& '%' != *fmt)
		{
			fmt++;
			i++;
		}
		arg->format = ft_substr(fmt - i, 0, i);
		set_attr(arg, ap);
	}
	*start = *start + i;
	arg->conv = *fmt;
}

void set_str_arg(t_arg *arg, va_list ap)
{
	arg->wvar = NULL;
	if ('c' == arg->conv)
		malloc_c(arg, va_arg(ap, int));
	else if ('s' == arg->conv)
		arg->wvar = arg_strncpy(arg, va_arg(ap, char*), arg->precis);
	else if ('d' == arg->conv || 'i' == arg->conv)
		arg->wvar = get_abs_base(arg, ap);
	else if ('u' == arg->conv)
		arg->wvar = get_base(va_arg(ap, unsigned int), 10, B10, 0);
	else if ('p' == arg->conv)
		arg->wvar = get_addon_base(va_arg(ap, unsigned long), 16, B16l, "0x");
	else if ('X' == arg->conv || 'x' == arg->conv)
		arg->wvar = get_addon_base(va_arg(ap, int), 16, B16U, "0x");
	else if ('x' == arg->conv)
		arg->wvar = get_addon_base(va_arg(ap, int), 10, B16l, "0x");
//	else if ('%' == arg->conv)
//		arg->var = NULL;
}

int add_arg(t_arg **farg, const char *fmt, int *start, int pos, va_list ap)
{
	t_arg *warg;

	if (!(warg = (t_arg*) malloc_(sizeof(t_arg))))
		return (ERROR);
	if (!(warg->str = ft_substr(fmt, *start, pos)))
		return (ERROR);
	warg->wvar = NULL;
	*start += pos;
	warg->length = 0;
	warg->precis = 0;
	warg->white_nb = 0;
	warg->white_char = ' ';
	warg->zero = 0;
	warg->next = 0;
	warg->sign = 0;
	get_conv(ap, fmt, start, warg);
	if (fmt[*start])
		*start = *start + 2;
	set_str_arg(warg, ap);
	ft_lstadd_back(farg, warg);
	return (warg->conv ? OK : SUCCESS);
}

