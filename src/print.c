#include "ft_printf.h"


void print_c (t_arg *arg)
{
	ft_putchar((char)arg->var[0]);
}

void print_s (t_arg *arg)
{
	ft_putstr((char *)arg->var[0]);
}

void print_d (t_arg *arg)
{
	ft_putnbr((int)arg->var[0]);
}

void print_u (t_arg *arg)
{
	ft_putnbr((unsigned int)arg->var[0]);
}

void print_p (t_arg *arg)
{
	ft_putnbr((unsigned int)arg->var[0]);
}

void print_x (t_arg *arg)
{
	ft_putnbr((unsigned int)arg->var[0]);
}

void set_print(t_arg *arg)
{
	if ('c' == arg->conv)
		arg->print = &print_c;
	else if ('s' == arg->conv)
		arg->print = &print_s;
	else if ('d' == arg->conv || 'i' == arg->conv)
		arg->print = &print_d;
	else if ('u' == arg->conv)
		arg->print = &print_d;
	else if ('p' == arg->conv)
		arg->print = &print_p;
	else if ('X' == arg->conv || 'x' == arg->conv)
		arg->print = &print_x;
	else if (!arg->conv)
		arg->print = NULL;
	else
	{
		arg->var[arg->nb_arg - 1] = "%";
		arg->print = &print_s;
	}
}
