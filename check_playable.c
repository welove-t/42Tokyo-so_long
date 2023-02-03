/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:18:41 by terabu            #+#    #+#             */
/*   Updated: 2023/02/03 13:38:47 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_playable(t_solong *sl)
{
	t_track	track;
	int		y;

	y = 0;
	track.line = malloc(sizeof(char *) * sl->row);
	while (y < sl->row)
	{
		track.line[y] = ft_strdup(sl->line[y]);
		y++;
	}
	track.x = sl->x;
	track.y = sl->y;
	check_goal(&track);
	free_array(track.line, sl->row);
	// free_array(track.line, sl->row);
}

void	check_goal(t_track *bt)
{
	int	i;
	int	dic[4];

	init_dic(dic);
	bt->line[bt->y][bt->x] = '0';
	i = dfs(bt->y, bt->x, bt, dic);
	printf("dfs:%d\n",i);
}

void	init_dic(int *dic)
{
	dic[0] = 0;
	dic[1] = 0;
	dic[2] = 0;
	dic[3] = 0;
}
