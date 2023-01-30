/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:37:37 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 13:31:19 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	output_item(t_window *win, t_map *map, t_item *item)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->line[i][j] == '1')
				put_item(win, item->wall, j * BASE, i * BASE);
			else if (map->line[i][j] == '0')
				put_item(win, item->space, j * BASE, i * BASE);
			else if (map->line[i][j] == 'C')
				put_item(win, item->collect, j * BASE, i * BASE);
			else if (map->line[i][j] == 'P')
				put_item(win, item->player, j * BASE, i * BASE);
			else if (map->line[i][j] == 'E')
				put_item(win, item->goal, j * BASE, i * BASE);
			j++;
		}
		i++;
	}
}

void	put_item(t_window *win, void *item, int w, int h)
{
	mlx_put_image_to_window(win->mlx, win->win, item, w, h);
}
