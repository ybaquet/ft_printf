#include "../ft_printf.h"

#include <stdio.h>
int get_attr_value(t_arg *arg, char *s, va_list ap, int to_free)
{
	int		value;

	if (!s || !*s)
	{
		arg->precis = (to_free) ? arg->precis : -1;
		return (0);
	}
	else if ('*' == s[0])
		return(va_arg(ap, int));
	else
		value  = ft_atoi(s);
	if (to_free)
		free_s(s);
	else
		arg->precis = -1;
	return (value);
}

void set_attr(t_arg *arg, va_list ap)
{
	int		pos;
	char	*pt;
	char	*wstr;

	pt = arg->fmt;
	while (pt && (*pt == '-' || *pt == '0'  || *pt == '+'))
	{
		if ('0' == *pt)
			arg->haszero = 1;
		else if ('+' == *pt)
			arg->sign = 1;
		else
			arg->left = 1;
		pt++;
	}
	arg->haszero = (arg->left) ? 0 : arg->haszero;
	pos = index_of(pt, '.');
	if (-1 == pos)
		arg->length = get_attr_value(arg, pt , ap, 0);
	else
	{
		wstr = ft_substr(pt, 0, pos);
		arg->length = get_attr_value(arg, wstr, ap, 1);
		wstr = ft_substr(pt, pos + 1, ft_strlen(pt) - pos + 1);
		arg->precis = get_attr_value(arg, wstr, ap, 1);
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
		arg->fmt = ft_substr(fmt - i, 0, i);
		set_attr(arg, ap);
		arg->addon = ('p' == arg->conv) ? "0x" : NULL;
		arg->length = ('p' == arg->conv) ? arg->length - 2 : arg->length;
	}
	*start = *start + i;
	arg->conv = *fmt;
}

void		compute_padd(t_arg *a)
{
	int l;

	l = ft_strlen(a->wvar);
	if ('s' != a->conv && 'c' != a->conv && ('%' != a->conv || !a->left))
	{
		if (-1 < a->precis || a->haszero)
			a->zero_nb = (-1 < a->precis) ? a->precis - l : a->length - l;
		a->zero_nb = (0 > a->zero_nb) ? 0 : a->zero_nb;
	}
	if ('c' == a->conv && a->wvar && !*(a->wvar))
		a->length -= 1;
	if (a->left)
		a->after = a->length - a->zero_nb - l;
	else
		a->before = a->length - a->zero_nb - l;
}

void set_str_arg(t_arg *arg, va_list ap)
{
	arg->wvar = NULL;
	if ('c' == arg->conv || '%' == arg->conv)
		malloc_c(arg, ('c' == arg->conv) ? va_arg(ap, int) : '%');
	else if ('s' == arg->conv)
		arg->wvar = arg_strncpy(arg, va_arg(ap, char*), arg->precis);
	else if ('d' == arg->conv || 'i' == arg->conv)
		arg->wvar = get_abs_base(arg, va_arg(ap, int));
	else if ('u' == arg->conv)
		arg->wvar = get_base(va_arg(ap, unsigned int), 10, B10, arg);
	else if ('p' == arg->conv)
		arg->wvar = get_base(va_arg(ap, unsigned long), 16, B16l, arg);
	else if ('X' == arg->conv)
		arg->wvar = get_base(va_arg(ap, long), 16, B16U, arg);
	else if ('x' == arg->conv)
		arg->wvar = get_base(va_arg(ap, long), 16, B16l, arg);
	compute_padd(arg);
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
	warg->addon = NULL;
	warg->precis = 0;
	warg->before = 0;
	warg->after = 0;
	warg->fmt = NULL;
	warg->zero_nb = 0;
	warg->next = 0;
	warg->sign = 0;
	warg->left = 0;
	warg->haszero = 0;
	get_conv(ap, fmt, start, warg);
	if (fmt[*start])
		*start = *start + 2;
	set_str_arg(warg, ap);
	ft_lstadd_back(farg, warg);
	return (warg->conv ? OK : SUCCESS);
}

