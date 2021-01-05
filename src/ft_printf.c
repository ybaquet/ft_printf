#include "ft_printf.h"

int globalMalloc = 0;
int globalFree = 0;


int free_all(t_arg *farg, int status)
{
	t_arg *warg;

	warg = farg;
	while (warg)
	{
		free_s(warg->wvar);
		free_s(warg->str);
		free_s(warg->format);
		free_arg(warg);
		warg = warg->next;
	}
	trace("\nMalloc:%d", globalMalloc);
	trace("\t\tfree:%d\n", globalFree);
	return (status);
}

void repet(char c, int nb, int flag)
{
	if (flag)
		while (nb-- > 0)
			ft_putchar(c);
}

int print_args(t_arg *farg, int status)
{
	t_arg	*warg;

	warg = farg;
	while (warg)
	{
//		white = warg->length  - warg->precis - ft_strlen(warg->wvar);
		ft_putstr(warg->str);
		repet(warg->white_char, warg->white_nb, !warg->left);
		if (warg->sign)
			ft_putchar('-');
		repet('0', warg->zero, 1);
		ft_putstr(warg->wvar);
		repet(warg->white_char, warg->white_nb, warg->left);
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
	return (print_args(farg, status));
}
