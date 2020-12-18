#include "ft_printf.h"

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
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str++ - 48;
	}
	return (result * sign);
}

char	*ft_substr(const char *s, int start, int len)
{
	char	*pt;
	int		i;

	i = 0;
	if (!(pt = malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (start--)
		s++;
	while (len-- && *s)
		pt[i++] = *s++;
	pt[i] = 0;
	return (pt);
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
