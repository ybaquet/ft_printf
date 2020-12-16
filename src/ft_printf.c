#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"


int free_all(t_arg *farg, int status)
{
	t_arg *warg;

	warg = farg;
	while (warg)
	{
		free(warg->attr);
		free(warg->str);
		free(warg);
		warg = warg->next;
	}
	return (status);
}

void repet(char c, int nb)
{
	while (nb-- > 0)
		ft_putchar(c);
}

int print(t_arg *farg, int status)
{
	t_arg *warg;

	warg = farg;
	while (warg)
	{
		if (warg->attr && !warg->attr->left)
		{
			repet(' ', warg->attr->width - warg->attr->precis);
			repet('0', warg->attr->precis);
		}
		ft_putstr(warg->str);
		if (warg->print)
			warg->print(warg);
		if (warg->attr && warg->attr->left)
		{
			repet('0', warg->attr->precis);
			repet(' ', warg->attr->width - warg->attr->precis);
		}
		warg = warg->next;
	}
	return (free_all(farg, status));
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
	return (print(farg, status));
}
