/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:02 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 11:14:56 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_solong *solong)
{
	init_window(solong);
	init_item(solong);
	init_player(solong);
	get_ccount(solong);
	solong->m_cnt = 0;
}

void	init_window(t_solong *s)
{
	s->win_wid = s->col * BASE;
	s->win_hei = s->row * BASE;
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->win_wid, s->win_hei, "so_long");
}

void	init_item(t_solong *s)
{
	s->player = mlx_xpm_file_to_image(s->mlx, "./images/player.xpm", &s->win_wid, &s->win_hei);
	s->wall = mlx_xpm_file_to_image(s->mlx, "./images/wall.xpm", &s->win_wid, &s->win_hei);
	s->space = mlx_xpm_file_to_image(s->mlx, "./images/empty.xpm", &s->win_wid, &s->win_hei);
	s->goal = mlx_xpm_file_to_image(s->mlx, "./images/goal.xpm", &s->win_wid, &s->win_hei);
	s->collect = mlx_xpm_file_to_image(s->mlx, "./images/collect.xpm", &s->win_wid, &s->win_hei);
}

void	init_player(t_solong *s)
{
	int	x;
	int	y;
	int	flg;

	y = 0;
	flg = 0;
	while (y < s->row)
	{
		x = 0;
		while (x < s->col)
		{
			if (s->line[y][x] == 'P')
			{
				s->x = x;
				s->y = y;
				flg = 1;
				break ;
			}
			x++;
		}
		if (flg == 1)
			break ;
		y++;
	}
}

void	get_ccount(t_solong *s)
{
	int	x;
	int	y;

	y = 0;
	s->c_cnt = 0;
	while (y < s->row)
	{
		x = 0;
		while (x < s->col)
		{
			if (s->line[y][x] == 'C')
				s->c_cnt++;
			x++;
		}
		y++;
	}
}
