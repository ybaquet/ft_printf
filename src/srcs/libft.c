/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:43:49 by yde-mont          #+#    #+#             */
/*   Updated: 2021/01/07 14:43:51 by yde-mont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_putchar(str[i++]);
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if ('-' == *str || '+' == *str)
	{
		if ('-' == *str)
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - 48;
	return (result * sign);
}

int		index_of(char *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s++ == c)
			return (i);
		i++;
	}
	return (NOTFOUND);
}

int		ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}
