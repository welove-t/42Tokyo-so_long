/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:19:54 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 11:01:39 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_solong *sl)
{
	char	c;

	c = sl->line[sl->y - 1][sl->x];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y - 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = '0';
	}
	else if (c == 'C')
	{
		sl->line[sl->y - 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = '0';
		sl->c_cnt--;
	}
	else if (c == 'E')
	{
		if (sl->c_cnt == 0)
			exit(0);
		else
			return ;
	}
	output_item(sl);
	init_player(sl);
}

void	move_d(t_solong *sl)
{
	char	c;

	c = sl->line[sl->y][sl->x + 1];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y][sl->x + 1] = 'P';
		sl->line[sl->y][sl->x] = '0';
	}
	else if (c == 'C')
	{
		sl->line[sl->y][sl->x + 1] = 'P';
		sl->line[sl->y][sl->x] = '0';
		sl->c_cnt--;
	}
	else if (c == 'E')
	{
		if (sl->c_cnt == 0)
			exit(0);
		else
			return ;
	}
	output_item(sl);
	init_player(sl);
}

void	move_s(t_solong *sl)
{
	char	c;

	c = sl->line[sl->y + 1][sl->x];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y + 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = '0';
	}
	else if (c == 'C')
	{
		sl->line[sl->y + 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = '0';
		sl->c_cnt--;
	}
	else if (c == 'E')
	{
		if (sl->c_cnt == 0)
			exit(0);
		else
			return ;
	}
	output_item(sl);
	init_player(sl);
}

void	move_a(t_solong *sl)
{
	char	c;

	c = sl->line[sl->y][sl->x - 1];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y][sl->x - 1] = 'P';
		sl->line[sl->y][sl->x] = '0';
	}
	else if (c == 'C')
	{
		sl->line[sl->y][sl->x - 1] = 'P';
		sl->line[sl->y][sl->x] = '0';
		sl->c_cnt--;
	}
	else if (c == 'E')
	{
		if (sl->c_cnt == 0)
			exit(0);
		else
			return ;
	}
	output_item(sl);
	init_player(sl);
}
