/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:04:07 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 10:16:43 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_solong *solong)
{
	if (keycode == KEY_W)
		move_w(solong);
	else if (keycode == KEY_S)
		move_s(solong);
	else if (keycode == KEY_A)
		move_a(solong);
	else if (keycode == KEY_D)
		move_d(solong);
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", solong->x, solong->y);
	return (0);
}
