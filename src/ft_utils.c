#include <unistd.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	if (str)
	{
		i = 0;
		while (str[i])
			ft_putchar(str[i++]);

	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(214748364);
		ft_putchar(8 + 48);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
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
