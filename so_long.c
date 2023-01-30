/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 09:39:28 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

int main()
{
	char	**line = NULL;
	void	*mlx;
	void	*win;
	void	*player;
	void	*empty;
	void	*goal;
	void	*wall;
	void	*flower;
	int		i;
	int		j;
	int		width = 416;
	int		height = 160;
	int		img_width;
	int		img_height;

	line = input_file();
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "test");

	player = mlx_xpm_file_to_image(mlx, "./images/char_1.xpm", &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	empty = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &img_width, &img_height);
	goal = mlx_xpm_file_to_image(mlx, "./images/goal.xpm", &img_width, &img_height);
	flower = mlx_xpm_file_to_image(mlx, "./images/flower.xpm", &img_width, &img_height);
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 13)
		{
			if (line[i][j] == '1')
				mlx_put_image_to_window(mlx, win, wall, j * 32, i * 32);
			else if (line[i][j] == '0')
				mlx_put_image_to_window(mlx, win, empty, j * 32, i * 32);
			else if (line[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, flower, j * 32, i * 32);
			else if (line[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, player, j * 32, i * 32);
			else if (line[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, goal, j * 32, i * 32);
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < width)
	// {
	// 	j = 0;
	// 	while (j < height)
	// 	{
	// 		mlx_pixel_put(mlx, win, i, j, 127);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_loop(mlx);

}

// gcc -lmlx -framework OpenGL -framework AppKit so_long.c
