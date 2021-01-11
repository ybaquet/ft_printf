/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:43:03 by yde-mont          #+#    #+#             */
/*   Updated: 2021/01/07 14:43:08 by yde-mont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_arg(t_arg *arg)
{
	free(arg->wvar);
	free(arg->str);
	free(arg->fmt);
	free(arg);
}

int		print_args(t_arg *farg)
{
	t_arg	*warg;
	t_arg	*parg;
	int		result;

	warg = farg;
	result = 0;
	while (warg)
	{
		parg = warg;
		result += ft_putstr(warg->str);
		while ((warg->before)-- > 0)
			result += ft_putchar(' ');
		if (warg->sign)
			result += ft_putchar((-1 == warg->sign) ? '-' : ' ');
		result += ft_putstr(warg->addon);
//		if (warg->zero_nb>10)
//		{
//			printf("<%d, %d>.\n", warg->zero_nb, warg->haszero);
//			warg->zero_nb=10;
//		}
		while (warg->haszero && (warg->zero_nb)-- > 0)
			result += ft_putchar('0');
		result += ft_putstr(warg->wvar);
		if ('c' == warg->conv && warg->wvar && !*(warg->wvar))
			result += ft_putchar(0);
		while ((warg->after)-- > 0)
			result += ft_putchar(' ');
		warg = warg->next;
		free_arg(parg);
	}
	return (result);
}

void	get_conv(va_list ap, const char *fmt, int *start, t_arg *arg)
{
	int i;

	arg->width = 0;
	arg->fmt = NULL;
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
		arg->fmt = arg_substr(arg, fmt - i, 0, i);
		set_attr(arg, ap, arg->fmt);
		arg->addon = ('p' == arg->conv) ? "0x" : NULL;
		arg->width = ('p' == arg->conv) ? arg->width - 2 : arg->width;
	}
	*start = *start + i;
	arg->conv = *fmt;
}

t_arg	*add_arg(const char *fmt, int *start, int pos, va_list ap)
{
	t_arg *warg;

	if (!(warg = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	if (!(warg->str = arg_substr(warg, fmt, *start, pos)))
		return (NULL);
	warg->wvar = NULL;
	*start += pos;
	warg->addon = NULL;
	warg->before = 0;
	warg->after = 0;
	warg->zero_nb = 0;
	warg->next = 0;
	warg->sign = 0;
	warg->right = 0;
	warg->haszero = 0;
	warg->status = SUCCESS;
	get_conv(ap, fmt, start, warg);
	if (fmt[*start])
		*start = *start + 2;
	last_proc_arg(warg, ap);
	return ((SUCCESS == warg->status) ? warg : NULL);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		start;
	int		pos;
	t_arg	*farg;
	t_arg	*warg;

	start = 0;
	pos = 0;
	farg = NULL;
	va_start(ap, fmt);
	while (start != ft_strlen((char*)fmt))
	{
		if ('%' == fmt[start + pos] || !fmt[start + pos])
		{
			warg = add_arg(fmt, &start, pos, ap);
			if (!warg)
				return (ERROR);
			ft_lstadd_back(&farg, warg);
			pos = -1;
		}
		pos++;
	}
	va_end(ap);
	return (print_args(farg));
}
