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

#include "../includes/ft_printf.h"

int		free_error(t_arg *farg)
{
	t_arg *parg;

	while (farg)
	{
		parg = farg;
		free(farg->wvar);
		free(farg->str);
		free(farg->fmt);
		free(farg);
		farg = parg->next;
	}
	return (ERROR);
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
