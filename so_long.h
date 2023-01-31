/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:12 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 09:44:33 by terabu           ###   ########.fr       */
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

typedef struct s_solong{
	void	*mlx;
	void	*win;
	int		win_wid;
	int		win_hei;
	int		img_wid;
	int		img_hei;
	void	*player;
	void	*space;
	void	*goal;
	void	*wall;
	void	*collect;
	int		fd;
	char	*filepath;
	char	**line;
	int		row;
	int		col;
	int		x;
	int		y;
}	t_solong;

// input file
void	input_file(t_solong *map);
void	get_ncount(t_solong *map);

// initalize
void	initialize(t_solong *solong);
void	init_window(t_solong *s);
void	init_item(t_solong *s);
void	init_player(t_solong *s);

// output item
void	output_item(t_solong *solong);
void	put_item(t_solong *solong, void *item, int w, int h);

// hook
int		key_press(int keycode, t_solong *solong);

#endif
