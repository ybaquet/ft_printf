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
# define B10 "0123456789"
# define B16U "0123456789ABCDEF"
# define B16l "0123456789abcdef"

typedef struct	s_arg
{
	char			*var;
	char			*wvar;
	char			conv;
	char			*str;
	int				precis;
	int				length;
	int				left;
	int				sign;
	struct s_arg	*next;
}				t_arg;

int				ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
int				add_arg(t_arg **argfirst, const char *fmt, int *start, int pos, va_list ap);
void			set_print(t_arg *arg);
char			*ft_substr(const char *s, int start, int len);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_atoi(const char *str);
int				index_of(char *s, char c);
int				ft_strlen(char *s);
void			ft_lstadd_back(t_arg **arg_list, t_arg *new_arg);
void			malloc_c(t_arg *arg, char c);
char			*get_abs_base(t_arg *arg, va_list ap);
char			*get_addon_base(long nb, int base, const char *str_base, char *addon);
char			*get_base(long nb, int base, const char *str_base, int addonlen);

#endif
