# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 14:06:56 by terabu            #+#    #+#              #
#    Updated: 2023/01/31 08:07:49 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c \
	   initialize.c \
	   output_item.c \
	   hook.c \
	   input_file.c
OBJS = $(SRCS:.c=.o)

PRINTFDIR = ./lib/ft_printf
GNLDIR = ./lib/get_next_line
# MLXDIR = ./lib/minilibx-linux

FT_PRINTF =  -L$(PRINTFDIR) -lftprintf
GNL = -L${GNLDIR}/ -lgnl

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ${PRINTFDIR}
	$(MAKE) -C ${GNLDIR}
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(FT_PRINTF) $(GNL) $(MLX)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ${PRINTFDIR} clean
	$(MAKE) -C ${GNLDIR} clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ${PRINTFDIR} fclean
	$(MAKE) -C ${GNLDIR} fclean

re: fclean all

.PHONY:	all clean fclean re
