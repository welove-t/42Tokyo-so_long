/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 11:37:31 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_solong	solong;

	input_file(&solong);
	initialize(&solong);
	output_item(&solong);
	mlx_hook(solong.win, X_EVENT_KEY_RELEASE, 0, &key_press, &solong);
	mlx_hook(solong.win, X_EVENT_KEY_EXIT, 0, &exit_solong, &solong);
	mlx_loop(solong.mlx);
	return (0);
}
