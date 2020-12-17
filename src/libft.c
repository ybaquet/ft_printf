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

int		ft_isdigit(int i)
{
	if ((i >= '0' && i <= '9'))
		return (1);
	if (i == '-' || i == '+' || i == '.')
		return (1);
	return (0);
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

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
