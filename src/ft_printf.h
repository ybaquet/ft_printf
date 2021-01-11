/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:52:36 by yde-mont          #+#    #+#             */
/*   Updated: 2021/01/07 13:18:13 by yde-mont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

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
	char			*wvar;
	char			*addon;
	char			conv;
	char			*str;
	int				hasprecis;
	int				precis;
	int				width;
	char			*fmt;
	int				haszero;
	int				zero_nb;
	int				right;
	int				before;
	int				after;
	int				sign;
	int				status;
	struct s_arg	*next;
}				t_arg;

int				ft_printf(const char *fmt, ...);
char			*arg_substr(t_arg *arg, const char *s, int start, int len);
void			set_attr(t_arg *arg, va_list ap, char *pt);
void			last_proc_arg(t_arg *arg, va_list ap);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_atoi(const char *s);
int				index_of(char *s, char c);
int				ft_strlen(char *s);
void			ft_lstadd_back(t_arg **arg_list, t_arg *new_arg);
char			*malloc_c(t_arg *arg, char c);
char			*get_abs_base(t_arg *arg, long nb);
char			*get_trunc_base(long nb, int base, const char *str_base, t_arg *arg);
char			*get_base(long nb, int base, const char *str_base, t_arg *arg);
char			*arg_strncpy(t_arg *arg, char *str, int n);

#endif
