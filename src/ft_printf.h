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
	int				precis;
	int				length;
	char			*fmt;
	int				haszero;
	int				zero_nb;
	int				left;
	int 			before;
	int				after;
	int				sign;
	struct s_arg	*next;
}				t_arg;

int				ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
int				add_arg(t_arg **argfirst, const char *fmt, int *start, int pos, va_list ap);
char			*ft_substr(const char *s, int start, int len);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int);
int				ft_atoi(const char *);
int				index_of(char *s, char c);
int				ft_strlen(char *s);
void			ft_lstadd_back(t_arg **arg_list, t_arg *new_arg);
char			*malloc_c(t_arg *arg, char c);
char			*get_abs_base(t_arg *arg, int nb);
char			*get_base(long nb, int base, const char *str_base, t_arg *arg);
char			*arg_strncpy(t_arg *arg, char *str, int n);
// A supprimer
void *malloc_(size_t);
void free_s(char *);
void free_arg(t_arg *);
void trace(char *fmt, int i);

// A supprimer
extern int globalMalloc;
extern int globalFree;

#endif
