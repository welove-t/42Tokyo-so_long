/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:02 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 11:34:13 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_window *win, t_item *item)
{
	init_window(win);
	init_item(win, item);
}

void	init_window(t_window *win)
{
	win->width = 416;
	win->height = 160;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, "test");
}

void	init_item(t_window *win, t_item *item)
{
	item->player = mlx_xpm_file_to_image(win->mlx, "./images/char_1.xpm", &item->width, &item->height);
	item->wall = mlx_xpm_file_to_image(win->mlx, "./images/wall.xpm", &item->width, &item->height);
	item->space = mlx_xpm_file_to_image(win->mlx, "./images/empty.xpm", &item->width, &item->height);
	item->goal = mlx_xpm_file_to_image(win->mlx, "./images/goal.xpm", &item->width, &item->height);
	item->collect = mlx_xpm_file_to_image(win->mlx, "./images/flower.xpm", &item->width, &item->height);
}
