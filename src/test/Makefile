NAME		= libftprintf.a

SRCS		= ft_printf.c
				sources/ft_arg_utils.c \
				sources/ft_arg.c \
					sources/ft_utils.c \
				sources/libft.c

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I./includes

OBJS		= $(SRCS:.c=.o}

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
