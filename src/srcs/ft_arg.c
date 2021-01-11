/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:44:11 by yde-mont          #+#    #+#             */
/*   Updated: 2021/01/07 14:44:22 by yde-mont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_attr_value(char *s, va_list ap, int to_free)
{
	int		value;

	if (!s || !*s)
		return (0);
	else if ('*' == s[0])
		return (va_arg(ap, int));
	else
		value = ft_atoi(s);
	if (to_free)
		free(s);
	return (value);
}

void	reevaluate_attr(t_arg *arg)
{
	if (arg->hasprecis && arg->precis < 0)
	{
		arg->hasprecis = 0;
		arg->haszero = 0;
	}
	if (arg->width < 0)
	{
		arg->width = - (arg->width);
		arg->right = 1;
		arg->haszero = 0;
//		arg->precis = (!arg->hasprecis) ? 0 : arg->precis;
//		arg->hasprecis = 1;
	}
}

void	set_attr(t_arg *arg, va_list ap, char *pt)
{
	int		pos;
	char	*wstr;

	while (pt && (*pt == '-' || *pt == '0' || *pt == ' '))
	{
		if ('0' == *pt)
			arg->haszero = 1;
		else if (' ' == *pt)
			arg->sign = 1;
		else
			arg->right = 1;
		pt++;
	}
	arg->haszero = (arg->right) ? 0 : arg->haszero;
	pos = index_of(pt, '.');
	if (-1 == pos)
	{
		arg->width = get_attr_value(pt, ap, 0);
		arg->hasprecis = 0;
	}
	else
	{
		wstr = arg_substr(arg, pt, 0, pos);
		arg->width = get_attr_value(wstr, ap, 1);
		wstr = arg_substr(arg, pt, pos + 1, ft_strlen(pt) - pos + 1);
		arg->precis = get_attr_value(wstr, ap, 1);
		arg->hasprecis = 1;
	}
	reevaluate_attr(arg);
}

void	compute_padd(t_arg *a)
{
	int l;

	l = ft_strlen(a->wvar);
	if (a->conv && 's' != a->conv && 'c' != a->conv && ('%' != a->conv || !a->right))
	{
		if (a->hasprecis || a->haszero)
		{
			a->zero_nb = (a->hasprecis) ? a->precis - l : a->width - l;
			a->zero_nb = (0 > a->zero_nb) ? 0 : a->zero_nb;
			a->haszero = 1;
		}
	}
	if ('c' == a->conv && a->wvar && !*(a->wvar))
		a->width -= 1;
	if (a->right)
		a->after = a->width - a->zero_nb - l;
	else
		a->before = a->width - a->zero_nb - l;
}

void	last_proc_arg(t_arg *arg, va_list ap)
{
	if (0 > arg->width)
	{
		arg->width = -(arg->width);
		arg->right = 1;
	}
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
		arg->wvar = get_base((unsigned long) va_arg(ap, long), 16, B16l, arg);
	else if ('X' == arg->conv)
		arg->wvar = get_trunc_base(va_arg(ap, long), 16, B16U, arg);
	else if ('x' == arg->conv)
		arg->wvar = get_trunc_base(va_arg(ap, long), 16, B16l, arg);
	compute_padd(arg);
}
