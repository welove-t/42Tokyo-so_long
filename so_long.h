/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:12 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 11:06:36 by terabu           ###   ########.fr       */
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

void	input_file(t_map *map);
void	get_ncount(t_map *map);

// initalize
void	initialize(t_window *win, t_item *item);
void	init_window(t_window *win);
void	init_item(t_window *win, t_item *item);

#endif
