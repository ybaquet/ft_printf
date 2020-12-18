#include "ft_printf.h"

int get_attr_value(char *s, t_arg *arg, va_list ap)
{
	if (!s || !*s)
		return (0);
	if ('*' == s[0])
		return (va_arg(ap, int));
	else
	{
		while (*s)
		{
			if (*s < '0' || *s > '9')
				break;
			s++;
		}
		*s = 0;
		return (ft_atoi(s));
	}
}

void set_attr(t_arg *arg, va_list ap, char *astr)
{
	int		pos;
	char	*pt;

	pt = astr;
	arg->left = 0;
	if ('-' == *pt)
	{
		arg->left = 1;
		pt++;
	}
	pos = index_of(pt, '.');
	arg->length = get_attr_value((-1 == pos) ? pt : ft_substr(pt, 0, pos),
			arg, ap);
	arg->precis = get_attr_value((-1 == pos) ? 	NULL :
			ft_substr(pt, pos + 1, ft_strlen(pt) - pos + 1), arg, ap);
	free(astr);
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
		set_attr(arg, ap, ft_substr(fmt - i, 0, i));
	}
	*start = *start + i;
	arg->conv = *fmt;
}

void set_str_arg(t_arg *arg, va_list ap)
{
	if ('c' == arg->conv && (arg->var = (char *)malloc(sizeof(char)*2)))
		malloc_c(arg, va_arg(ap, int));
	else if ('s' == arg->conv)
		arg->var = va_arg(ap, char*);
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
	else if ('%' == arg->conv)
		malloc_c(arg, '%');
	else if (!arg->conv)
		arg->var = NULL;
}

int add_arg(t_arg **farg, const char *fmt, int *start, int pos, va_list ap)
{
	t_arg *warg;

	if (!(warg = (t_arg*) malloc(sizeof(t_arg))))
		return (ERROR);
	if (!(warg->str = ft_substr(fmt, *start, pos)))
		return (ERROR);
	warg->wvar = NULL;
	*start += pos;
	warg->next = 0;
	warg->sign = 0;
	get_conv(ap, fmt, start, warg);
	if (fmt[*start])
	{
//		warg->var = va_arg(ap, void*);
		*start = *start + 2;
	}
	set_str_arg(warg, ap);
	ft_lstadd_back(farg, warg);
	return (warg->conv ? OK : SUCCESS);
}

