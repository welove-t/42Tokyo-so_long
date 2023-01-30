/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:12 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 07:53:40 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/ft_printf/ft_printf.h"

# define BASE 60

// EVENT
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

// KEY
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_window{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_window;

typedef struct s_item{
	int		width;
	int		height;
	void	*player;
	void	*space;
	void	*goal;
	void	*wall;
	void	*collect;
}	t_item;

typedef struct s_map{
	int		fd;
	char	*filepath;
	char	**line;
	int		row;
	int		col;
}	t_map;

typedef struct s_player{
	int		x;
	int		y;
}	t_player;

// input file
void	input_file(t_map *map);
void	get_ncount(t_map *map);

// initalize
void	initialize(t_window *win, t_map *map, t_item *item, t_player *player);
void	init_window(t_window *win, t_map *map);
void	init_item(t_window *win, t_item *item);
void	init_player(t_map *map, t_player *player);

// output item
void	output_item(t_window *win, t_map *map, t_item *item);
void	put_item(t_window *win, void *item, int w, int h);

#endif
