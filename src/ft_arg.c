#include "ft_printf.h"

int get_attr_value(char *s, t_arg *arg, va_list ap)
{
	if (!s || !*s)
		return (ERROR);
	arg->nb_arg++;
	if ('*' == s[0])
		return (va_arg(ap, int));
	else
	{
		while (*s)
		{
			if (*s < '0' || *s > '9')
				break;
		}
		return (ft_atoi(s));
	}
}

t_attr* get_attr(t_arg *arg, va_list ap, char *astr)
{
	t_attr *new;
	int pos;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	new->left = 0;
	if ('-' == *astr)
	{
		new->left = 1;
		astr++;
	}
	pos = index_of(astr, '.');
	new->width = get_attr_value((-1 == pos) ? astr : ft_substr(astr, 0, pos),
			arg, ap);
	new->precis = get_attr_value(
			(-1 == pos) ?
					NULL : ft_substr(astr, pos + 1, ft_strlen(astr) - pos + 1),
			arg, ap);
	free(astr);
	return (new);
}

void get_conv(va_list ap, const char *fmt, int *start, t_arg *arg)
{
	int i;

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
		arg->attr = get_attr(arg, ap, ft_substr(fmt - i, 0, i));
	}
	else
		ft_putstr("Coucou\n");
	*start = *start + i + 1;
	arg->conv = *fmt;
}

int add_arg(t_arg **argfirst, const char *fmt, int *start, int pos, va_list ap)
{
	t_arg *warg;

	if (!(warg = (t_arg*) malloc(sizeof(t_arg))))
		return (ERROR);
	if (!(warg->str = ft_substr(fmt, *start, pos)))
		return (ERROR);
	*start += pos;
	warg->nb_arg = 0;
	warg->next = 0;
	get_conv(ap, fmt, start, warg);
	if (fmt[*start])
		warg->var[warg->nb_arg] = va_arg(ap, void*);
	set_print(warg);
	ft_lstadd_back(argfirst, warg);
	(*start)++;
	return (warg->conv ? OK : SUCCESS);
}

