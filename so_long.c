/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by terabu            #+#    #+#             */
/*   Updated: 2023/02/01 08:51:23 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	solong;
	t_map		map;

	check_pre(argc, argv);
	input_file(&map, argv[1]);
	check_map(&map);
	printf("OK!\n");
	initialize(&solong);
	output_item(&solong);
	mlx_hook(solong.win, X_EVENT_KEY_RELEASE, 0, &key_press, &solong);
	mlx_hook(solong.win, X_EVENT_KEY_EXIT, 0, &exit_solong, &solong);
	mlx_loop(solong.mlx);
	return (0);
}

__attribute((destructor))
static void destructor() {
    system("leaks -q so_long");
}
