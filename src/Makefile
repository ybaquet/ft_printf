# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    liv_ft_printf.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yde-mont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 10:36:47 by yde-mont          #+#    #+#              #
#    Updated: 2021/01/12 10:36:58 by yde-mont         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES = ft_printf.c \
  			ft_arg_utils.c \
			ft_arg.c \
			ft_utils.c \
			libft.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	mkdir -p obj
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<


clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean re norme all clean
