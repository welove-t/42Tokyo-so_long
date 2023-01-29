/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:24:41 by terabu            #+#    #+#             */
/*   Updated: 2023/01/28 11:55:02 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./walk_0.xpm";
	// char	*relative_path = "./images/char/walk_0.xpm/";
	int		img_width = 600;
	int		img_height = 400;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img_width, img_height, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img,  50 , 50);
	// printf("%p\n", img);
	mlx_loop(mlx);

}
