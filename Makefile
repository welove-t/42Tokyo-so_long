# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 14:06:56 by terabu            #+#    #+#              #
#    Updated: 2023/02/05 15:09:54 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c \
	   check.c \
	   check_playable.c \
	   back_track.c \
	   initialize.c \
	   output_item.c \
	   output_print.c \
	   hook.c \
	   move.c \
	   input_file.c \
	   error.c \
	   close.c
OBJS = $(SRCS:.c=.o)

PRINTFDIR = ./lib/ft_printf
GNLDIR = ./lib/get_next_line
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
