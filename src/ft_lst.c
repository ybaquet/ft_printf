#include "ft_printf.h"

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
