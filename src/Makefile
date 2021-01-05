NAME		= libftprintf.a

SRCS		= ft_printf.c \
				srcs/ft_arg_utils.c \
				srcs/ft_arg.c \
				srcs/ft_utils.c \
				srcs/libft.c

OBJS		= ${SRCS:.c=.o}

#%.o : %.c	ft_printf.h
#			$(CC) -c $<

CC			= gcc $(CFLAGS)

CFLAGS		= -Wall -Wextra -Werror

AR			= ar -rcs

all :		$(NAME)

$(NAME) :	$(OBJS)
			$(AR) $@ $(OBJS)
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
