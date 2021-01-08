/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:06:42 by yde-mont          #+#    #+#             */
/*   Updated: 2021/01/07 15:06:44 by yde-mont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

t_arg	*ft_lstlast(t_arg *lst)
{
	t_arg *last;

	last = NULL;
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

void	ft_lstadd_back(t_arg **alst, t_arg *new)
{
	t_arg *last;
	t_arg *first;

	first = *alst;
	if (new)
	{
		if (first)
		{
			last = ft_lstlast(first);
			last->next = new;
		}
		else
			*alst = new;
	}
}
