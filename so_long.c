/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 13:14:33 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_window	win;
	t_item		item;
	t_map		map;

	input_file(&map);
	initialize(&win, &map, &item);
	output_item(&win, &map, &item);
	mlx_loop(win.mlx);
	return (0);
}

