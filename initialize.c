/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:02 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 08:01:17 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_window *win, t_map *map, t_item *item, t_player *player)
{
	init_window(win, map);
	init_item(win, item);
	init_player(map, player);
}

void	init_window(t_window *win, t_map *map)
{
	win->width = map->col * BASE;
	win->height = map->row * BASE;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, "so_long");
}

void	init_item(t_window *win, t_item *item)
{
	item->player = mlx_xpm_file_to_image(win->mlx, "./images/player.xpm", &item->width, &item->height);
	item->wall = mlx_xpm_file_to_image(win->mlx, "./images/wall.xpm", &item->width, &item->height);
	item->space = mlx_xpm_file_to_image(win->mlx, "./images/empty.xpm", &item->width, &item->height);
	item->goal = mlx_xpm_file_to_image(win->mlx, "./images/goal.xpm", &item->width, &item->height);
	item->collect = mlx_xpm_file_to_image(win->mlx, "./images/collect.xpm", &item->width, &item->height);
}

void	init_player(t_map *map, t_player *player)
{
	int	x;
	int	y;
	int	flg;

	y = 0;
	flg = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->line[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
				flg = 1;
				break ;
			}
			x++;
		}
		if (flg == 1)
			break ;
		y++;
	}
}
