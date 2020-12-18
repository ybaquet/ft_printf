#include "ft_printf.h"

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
	if (!(value = (char *)Malloc(sizeof(char) * (len + 1))))
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

char		*get_abs_base(t_arg *arg, va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	if (0 > nb)
	{
		arg->sign = 1;
		nb = -nb;
	}
	return get_base(nb, 10, B10, 0);
}

void	malloc_c(t_arg *arg, char c)
{
	if (!(arg->wvar = (char *)malloc(sizeof(char)*2)))
	{
		arg->wvar[0] = c;
		arg->wvar[1] = 0;
	}
}
