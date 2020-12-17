/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:52:36 by yde-mont          #+#    #+#             */
/*   Updated: 2020/12/08 17:57:30 by yde-mont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define OK 1
# define SUCCESS 0
# define ERROR -1
# define NOTFOUND -1
# define ENDCONV ' '

typedef struct	s_attr
{
	int		precis;
	int		width;
	int		left;
	int		len;
	char	*var;
}				t_attr;

typedef struct	s_arg
{
	void			*var;
	t_attr			*attr;
	char			conv;
	char			*str;
	void			(*print)(struct s_arg *);
	struct s_arg	*next;
}				t_arg;

int		ft_printf(const char *fmt, ...);
int		add_arg(t_arg **argfirst, const char *fmt, int *start, int pos, va_list ap);
void	set_print(t_arg *arg);
char	*ft_substr(const char *s, int start, int len);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
int		ft_isdigit(int i);
int		ft_strcmp(const char *s1, const char *s2);
int		index_of(char *s, char c);
int		ft_strlen(char *s);
void	ft_lstadd_back(t_arg **arg_list, t_arg *new_arg);

#endif
