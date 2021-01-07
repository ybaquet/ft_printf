#include "../ft_printf.h"

char	*arg_strncpy(t_arg *arg, char *str, int n)
{
	char	*pt;
	int		l;

	l = 0;
	if (!str)
		str = "(null)";
	if (0 > n)
		n = ft_strlen(str);
	if (!(pt = malloc_((n + 1) * sizeof(char))))
		return (NULL);
	while ((pt[l] = *str++) && n--)
		l++;
	pt[l] = 0;
	if (arg->left)
		arg->after = arg->length - l;
	else
		arg->before = arg->length - l;
	return (pt);
}

char *get_base(long nb, int base, const char *str_base, t_arg *arg)
{
	char	*value;
	long	level;
	int		len;

	if (!arg->precis)
		return malloc_c(arg, 0);
	level = base;
	len = 1;
	while(level <= nb && 0 < level)
	{
		level *= base;
		len++;
	}
	if (!(value = (char *)malloc_(sizeof(char) * (len + 1))))
		return NULL;
	value[len--] = 0;

	arg->addon = ('p' == arg->conv) ? "0x" : NULL;
	arg->length  = ('p' == arg->conv) ? arg->length - 2 : arg->length;
	while (len >= 0)
	{
		value[len] = str_base[nb % base];
		nb = nb / base;
		len--;
	}
	return (value);
}

char		*get_abs_base(t_arg *a, int nb)
{
	char	*value;
	int		l;

	if (0 > nb)
	{
		a->sign = -1;
		nb = -nb;
	}
	a->length = (a->sign) ? a->length - 1 : a->length;
	value = get_base(nb, 10, B10, a);
	l = ft_strlen(value);
	if (-1 < a->precis || a->haszero)
		a->zero_nb = (-1 < a->precis) ? a->precis - l : a->length - l;
	a->zero_nb = (0 > a->zero_nb) ? 0 : a->zero_nb;
	if (a->left)
		a->after = a->length - a->zero_nb - l;
	else
		a->before = a->length - a->zero_nb - l;
	return (value);
}

char	*malloc_c(t_arg *arg, char c)
{
	if ((arg->wvar = (char *)malloc_(sizeof(char)* (c) ? 2 : 1)))
	{
		if (c)
			arg->wvar[0] = c;
		arg->wvar[(c) ? 1 : 0] = 0;
	}
	return (arg->wvar);
}
