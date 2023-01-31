/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:04:07 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 09:42:30 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_solong *solong)
{
	if (keycode == KEY_W)
		solong->y++;
	else if (keycode == KEY_S)
		solong->y--;
	else if (keycode == KEY_A)
		solong->x--;
	else if (keycode == KEY_D)
		solong->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", solong->x, solong->y);
	return (0);
}
