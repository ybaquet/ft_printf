/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:05:15 by yde-mont          #+#    #+#             */
/*   Updated: 2021/01/07 15:05:16 by yde-mont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*arg_substr(t_arg *arg, const char *s, int start, int len)
{
	char	*pt;
	int		i;

	i = 0;
	if (!(pt = malloc((len + 1) * sizeof(char))))
	{
		arg->status = ERROR;
		return (NULL);
	}
	while (start--)
		s++;
	while (len-- && *s)
		pt[i++] = *s++;
	pt[i] = 0;
	return (pt);
}

char	*arg_strncpy(t_arg *arg, char *str, int n)
{
	char	*pt;
	int		l;

	l = 0;
	if (!str)
		str = "(null)";
	if (0 > n || !(arg->hasprecis))
		n = ft_strlen(str);
	if (!(pt = malloc((n + 1) * sizeof(char))))
		return (NULL);
	while ((pt[l] = *str++) && n--)
		l++;
	pt[l] = 0;
	if (arg->right)
		arg->after = arg->width - l;
	else
		arg->before = arg->width - l;
	return (pt);
}

char	*get_base(long nb, int base, const char *str_base, t_arg *arg)
{
	char			*value;
	unsigned long 	level;
	unsigned long	ul;
	int		len;

	if (arg->hasprecis && 0 == nb)
		return (malloc_c(arg, 0));
	level = base;
	len = 1;
	ul = (unsigned long) nb;
	while (level <= ul && 0 < level)
		level = (len++) ? base * level : base * level;
	if (!(value = (char *)malloc(sizeof(char) * (len + 1))))
	{
		arg->status = ERROR;
		return (NULL);
	}
	value[len--] = 0;
	arg->addon = ('p' == arg->conv) ? "0x" : NULL;
	arg->width = ('p' == arg->conv) ? arg->width - 2 : arg->width;
	while (len >= 0)
	{
		value[len--] = str_base[ul % base];
		ul = ul / base;
	}
	return (value);
}

char	*get_trunc_base(long nb, int base, const char *str_base, t_arg *arg)
{
	char	*value;
	char	*tvalue;
	int		len;

	value = get_base(nb, base, str_base, arg);
	len = ft_strlen(value);
	if (len > 8)
	{
		tvalue = arg_substr(arg, value, len - 8, 8);
		free(value);
		return (tvalue);
	}
	return (value);
}

char	*get_abs_base(t_arg *a, long nb)
{
	char	*value;
	int		l;

	if (0 > nb)
	{
		a->sign = -1;
		nb = -nb;
	}
	a->width = (a->sign) ? a->width - 1 : a->width;
	value = get_base(nb, 10, B10, a);
	l = ft_strlen(value);
	if (a->hasprecis || a->haszero)
		a->zero_nb = (a->hasprecis) ? a->precis - l : a->width - l;
	a->zero_nb = (0 > a->zero_nb) ? 0 : a->zero_nb;
	if (a->right)
		a->after = a->width - a->zero_nb - l;
	else
		a->before = a->width - a->zero_nb - l;
	return (value);
}

char	*malloc_c(t_arg *arg, char c)
{
	if ((arg->wvar = (char *)malloc(sizeof(char) * (c) ? 2 : 1)))
	{
		if (c)
			arg->wvar[0] = c;
		arg->wvar[(c) ? 1 : 0] = 0;
	}
	return (arg->wvar);
}
