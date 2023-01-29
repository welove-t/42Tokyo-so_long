# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 09:34:19 by terabu            #+#    #+#              #
#    Updated: 2022/11/05 08:18:10 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
SRCS := ft_printf.c \
		ft_printf_char.c \
		ft_printf_str.c \
		ft_printf_int.c \
		ft_printf_uint.c \
		ft_printf_hex.c \
		ft_printf_pointer.c \
		ft_printf_percent.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY:	all clean fclean re
