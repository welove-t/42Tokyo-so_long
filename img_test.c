/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:15:14 by terabu            #+#    #+#             */
/*   Updated: 2023/01/29 13:18:14 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int main()
{
	void *mlx;
	void *win;
	void *img;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "test");
	// img = mlx_xpm_file_to_image(mlx, "bandit_Idle_1.xpm", &img_width, &img_height);
	// img = mlx_xpm_file_to_image(mlx, "bandit_Idle_1.xpm", &img_width, &img_height);
	// img = mlx_xpm_file_to_image(mlx, "flower.xpm", &img_width, &img_height);
	// img = mlx_xpm_file_to_image(mlx, "goal.xpm", &img_width, &img_height);
	// img = mlx_xpm_file_to_image(mlx, "wall.xpm", &img_width, &img_height);
	img = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &img_width, &img_height);
	printf("img:%p\n", img);
	printf("width:%d\n", img_width);
	printf("heigh:%d\n", img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// gcc -lmlx -framework OpenGL -framework AppKit test.c
