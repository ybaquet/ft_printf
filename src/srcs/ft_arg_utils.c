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
	arg->white = arg->length - l;
	return (pt);
}

char *get_base(long nb, int base, const char *str_base, int addonlen)
{
	char	*value;
	long	level;
	int		len;

	level = base;
	len = addonlen + 1;
	while(level <= nb && 0 < level)
	{
		level *= base;
		len++;
	}
	if (!(value = (char *)malloc_(sizeof(char) * (len + 1))))
		return NULL;
	value[len--] = 0;
	while (len >= addonlen)
	{
		value[len] = str_base[nb % base];
		nb = nb / base;
		len--;
	}
	return (value);
}

char		*get_addon_base(long nb, int base, const char *str_base, char *addon)
{
	char	*value;
	int		i;

	i = 0;
	value = get_base(nb, base, str_base, ft_strlen((char*)addon));
	if (addon)
	while (*addon)
		value[i++] = *addon++;
	return (value);
}

char		*get_abs_base(t_arg *a, va_list ap)
{
	int		nb;
	char	*value;
//	int		zero;

//	zero = (NULL != a->fmt && '0' == *(a->fmt) && -1 == a->precis) ? 1 : 0;
	nb = va_arg(ap, int);
	if (0 > nb)
	{
		a->sign = 1;
		a->length -= 1;
		nb = -nb;
	}
	value = get_base(nb, 10, B10, 0);
	a->precis = (ft_strlen(value) > a->precis) ? 0 : a->precis - ft_strlen(value);
	a->white = a->length - a->precis - ft_strlen(value);
	a->zero = (a->haszero) ? a->white : a->precis;
	a->white = (a->haszero) ? 0 : a->white;
	return (value);
}

void	malloc_c(t_arg *arg, char c)
{
	if ((arg->wvar = (char *)malloc_(sizeof(char)*2)))
	{
		arg->wvar[0] = c;
		arg->wvar[1] = 0;
	}
}
