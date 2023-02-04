/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:18:41 by terabu            #+#    #+#             */
/*   Updated: 2023/02/04 11:30:19 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_bt_collect(t_track *bt, t_track *tmp, t_solong *sl);

void	check_playable(t_solong *sl)
{
	t_track	track;
	t_track	tmp;
	int		y;

	y = 0;
	track.line = malloc(sizeof(char *) * sl->row);
	tmp.line = malloc(sizeof(char *) * sl->row);
	while (y < sl->row)
	{
		track.line[y] = ft_strdup(sl->line[y]);
		tmp.line[y] = ft_strdup(sl->line[y]);
		y++;
	}
	track.x = sl->x;
	track.y = sl->y;
	tmp.line[track.y][track.x] = '0';
	check_goal(track);
	// check_collect(track, tmp, sl);
	free_array(track.line, sl->row);
	free_array(tmp.line, sl->row);
}

void	check_goal(t_track bt)
{
	int	i;
	int	dic[4];

	init_dic(dic);
	bt.line[bt.y][bt.x] = '0';
	// i = dfs_goal(bt.y, bt.x, &bt, dic);
	i = dfs_goal(bt.y, bt.x, &bt);
	printf("dfs-g:%d\n",i);
}

void	check_collect(t_track bt, t_track tmp, t_solong *sl)
{
	int	i;
	int	dic[4];

	i = 0;
	while (1)
	{
		init_dic(dic);
		printf("bt-x:%d\n", bt.x);
		printf("bt-y:%d\n", bt.y);
		// printf("dfs-c:%d\n",dfs_collect(bt.y, bt.x, &bt, dic));
		i++;
		if (i < sl->c_cnt)
			init_bt_collect(&bt, &tmp, sl);
		else
			break ;
	}
}

static void	init_bt_collect(t_track *bt, t_track *tmp, t_solong *sl)
{
	int	i;
	// int	x_tmp;
	// int	y_tmp;

	i = 0;
	// x_tmp = bt->x;
	// y_tmp = bt->y;
	tmp->line[bt->y][bt->x] = '0';
	while (i < sl->row)
	{
		ft_strlcpy(bt->line[i], tmp->line[i], sl->col);
		i++;
	}
	// bt->line[sl->y][sl->x] = '0';
	// bt->line[y_tmp][x_tmp] = '0';
	// tmp->line[y_tmp][x_tmp] = '0';
	// bt->x = x_tmp;
	// bt->y = y_tmp;
}

void	init_dic(int *dic)
{
	dic[0] = 0;
	dic[1] = 0;
	dic[2] = 0;
	dic[3] = 0;
}
