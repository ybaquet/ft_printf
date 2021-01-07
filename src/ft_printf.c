#include "ft_printf.h"

int globalMalloc = 0;
int globalFree = 0;


int print_args(t_arg *farg, int status)
{
	t_arg	*warg;
	t_arg	*parg;

	warg = farg;
	while (warg)
	{
		parg = warg;
		ft_putstr(warg->str);
		while ((warg->before)-- > 0)
			ft_putchar(' ');
		if (warg->sign)
			ft_putchar((-1 == warg->sign) ? '-' : '+');
		ft_putstr(warg->addon);
		while ((warg->zero_nb)-- > 0)
			ft_putchar('0');
		ft_putstr(warg->wvar);
		if ('c' == warg->conv && warg->wvar && !*(warg->wvar))
			write(1, warg->wvar, 1);
		while ((warg->after)-- > 0)
			ft_putchar(' ');
		warg = warg->next;
		free_s(parg->wvar);
		free_s(parg->str);
		free_s(parg->fmt);
		free_arg(parg);
	}
	return (status);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int start;
	int pos;
	int status;
	t_arg *farg;

	start = 0;
	pos = 0;
	farg = NULL;
	status = OK;
	va_start(ap, fmt);
	while (OK == status)
	{
		if ('%' == fmt[start + pos] || !fmt[start + pos])
		{
			status = add_arg(&farg, fmt, &start, pos, ap);
			pos = -1;
		}
		pos++;
	}
	va_end(ap);
	return (print_args(farg, status));
}
