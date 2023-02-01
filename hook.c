/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:04:07 by terabu            #+#    #+#             */
/*   Updated: 2023/02/01 14:01:33 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_solong *sl)
{
	char	point;

	if (sl->line[sl->y][sl->x] == 'N')
		point = 'E';
	else
		point = '0';
	if (keycode == KEY_W)
		move_w(sl, point);
	else if (keycode == KEY_S)
		move_s(sl, point);
	else if (keycode == KEY_A)
		move_a(sl, point);
	else if (keycode == KEY_D)
		move_d(sl, point);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	exit_solong(t_solong *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	free_array(sl->line, sl->row);
	exit(0);
}
