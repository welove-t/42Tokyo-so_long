/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:12 by terabu            #+#    #+#             */
/*   Updated: 2023/02/04 12:41:49 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "mlx.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/ft_printf/ft_printf.h"

# define BASE 60

// EVENT
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

// KEY
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

// ERROR
//   file
# define ERROR_ARGS		"not args 2"
# define ERROR_FILE		"not exist file"
# define ERROR_BER		"not ber file"

//   map
# define ERROR_RECT			"not rectangular"
# define ERROR_CLOSEMAP		"not close map"
# define ERROR_WALL			"not surrounded by walls"
# define ERROR_ITEM			"ng item"
# define ERROR_COLLECT		"no collect"
# define ERROR_PLAYER		"not one player"
# define ERROR_GOAL			"not one goal"
# define PLAYABLE_GOAL		"not playable(can't reach the goal)"
# define PLAYABLE_COLLECT	"not playable(can't get all collect)"

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
	void	*ongoal;
	char	*filepath;
	char	**line;
	int		row;
	size_t	col;
	int		x;
	int		y;
	int		m_cnt;
	int		c_cnt;
	bool	clear;
}	t_solong;

typedef struct s_map{
	int		fd;
	char	*filepath;
	char	**line;
	int		start_row;
	int		end_row;
	int		c_cnt;
	int		row;
	size_t	col;
}	t_map;

typedef struct s_track{
	int		x;
	int		y;
	int		c_cnt;
	char	**line;
}	t_track;

// check
void	check_pre(int argc, char **argv);
void	check_map(t_map *map);
void	check_rect_wall(char *s, t_map *map, int y);
void	check_item(char *s, t_map *map, int y);

// playable
void	check_playable(t_solong *sl);
void	check_goal(t_solong *sl);
void	check_collect(t_solong *sl);
void	init_dic(int *dic);
int		dfs_goal(int i, size_t j, t_track *bt);
int		dfs_collect(int i, size_t j, t_track *bt);

// input file
void	input_file(t_map *map, char *filepath);
void	get_ncount(t_map *map);
char	*gnl_skip_n(int fd);
void	set_map_row(t_map *map);
void	set_map_to_solong(t_map *map, t_solong *sl);

// initalize
void	initialize(t_solong *solong);
void	init_window(t_solong *s);
void	init_item(t_solong *s);
void	init_player(t_solong *s);
void	init_after_move(t_solong *sl);

// output item
void	output_item(t_solong *solong);
void	put_item(t_solong *solong, void *item, int w, int h);

// hook
int		key_press(int keycode, t_solong *solong);
int		exit_solong(t_solong *sl);

// move nomal
void	move_w(t_solong *sl, char point);
void	move_s(t_solong *sl, char point);
void	move_a(t_solong *sl, char point);
void	move_d(t_solong *sl, char point);

// move ongoal
void	move_w_n(t_solong *sl);
void	move_s_n(t_solong *sl);
void	move_a_n(t_solong *sl);
void	move_d_n(t_solong *sl);

// print
void	print_move_cnt(t_solong *sl);
void	print_error_msg(char const *message);

// close
void	free_array(char **line, int row);
void	error_map(char **line, int row, const char *msg);

#endif
