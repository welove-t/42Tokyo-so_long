/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 11:34:42 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_window	win;
	t_item		item;
	t_map		map;
	int			i;
	int			j;

	input_file(&map);
	initialize(&win, &item);
	i = 0;

	while (i < 5)
	{
		j = 0;
		while (j < 13)
		{
			if (map.line[i][j] == '1')
				mlx_put_image_to_window(win.mlx, win.win, item.wall, j * 32, i * 32);
			else if (map.line[i][j] == '0')
				mlx_put_image_to_window(win.mlx, win.win, item.space, j * 32, i * 32);
			else if (map.line[i][j] == 'C')
				mlx_put_image_to_window(win.mlx, win.win, item.collect, j * 32, i * 32);
			else if (map.line[i][j] == 'P')
				mlx_put_image_to_window(win.mlx, win.win, item.player, j * 32, i * 32);
			else if (map.line[i][j] == 'E')
				mlx_put_image_to_window(win.mlx, win.win, item.goal, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_loop(win.mlx);

}

// gcc -lmlx -framework OpenGL -framework AppKit so_long.c
