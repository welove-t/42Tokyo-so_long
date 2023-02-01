/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:19:54 by terabu            #+#    #+#             */
/*   Updated: 2023/02/01 13:46:03 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	judge_clear(t_solong *sl, int next_y, size_t next_x)
{
	if (sl->c_cnt == 0)
		exit_solong(sl);
	else
	{
		sl->line[sl->y][sl->x] = '0';
		sl->line[next_y][next_x] = 'N';
	}
}

void	move_w(t_solong *sl, char point)
{
	char	c;

	c = sl->line[sl->y - 1][sl->x];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y - 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = point;
	}
	else if (c == 'C')
	{
		sl->line[sl->y - 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = point;
		sl->c_cnt--;
	}
	else if (c == 'E')
		judge_clear(sl, sl->y - 1, sl->x);
	init_after_move(sl);
}

void	move_d(t_solong *sl, char point)
{
	char	c;

	c = sl->line[sl->y][sl->x + 1];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y][sl->x + 1] = 'P';
		sl->line[sl->y][sl->x] = point;
	}
	else if (c == 'C')
	{
		sl->line[sl->y][sl->x + 1] = 'P';
		sl->line[sl->y][sl->x] = point;
		sl->c_cnt--;
	}
	else if (c == 'E')
		judge_clear(sl, sl->y, sl->x + 1);
	init_after_move(sl);
}

void	move_s(t_solong *sl, char point)
{
	char	c;

	c = sl->line[sl->y + 1][sl->x];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y + 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = point;
	}
	else if (c == 'C')
	{
		sl->line[sl->y + 1][sl->x] = 'P';
		sl->line[sl->y][sl->x] = point;
		sl->c_cnt--;
	}
	else if (c == 'E')
		judge_clear(sl, sl->y + 1, sl->x);
	init_after_move(sl);
}

void	move_a(t_solong *sl, char point)
{
	char	c;

	c = sl->line[sl->y][sl->x - 1];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y][sl->x - 1] = 'P';
		sl->line[sl->y][sl->x] = point;
	}
	else if (c == 'C')
	{
		sl->line[sl->y][sl->x - 1] = 'P';
		sl->line[sl->y][sl->x] = point;
		sl->c_cnt--;
	}
	else if (c == 'E')
		judge_clear(sl, sl->y, sl->x - 1);
	init_after_move(sl);
}
