/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:18:41 by terabu            #+#    #+#             */
/*   Updated: 2023/02/05 14:56:58 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	go_next(int dir, int *nij, t_track *bt);

int	dfs_goal(int i, int j, t_track *bt)
{
	int	dir;
	int	nij[2];

	if (bt->line[i][j] == 'E')
		return (1);
	bt->line[i][j] = 'x';
	dir = 0;
	while (dir < 4)
	{
		nij[0] = i;
		nij[1] = j;
		if (go_next(dir, nij, bt) != -1)
		{
			if (dfs_goal(nij[0], nij[1], bt))
				return (1);
		}
		dir++;
	}
	return (0);
}

int	dfs_collect(int i, int j, t_track *bt)
{
	int	dir;
	int	nij[2];

	if (bt->line[i][j] == 'C')
	{
		if (!(--bt->c_cnt))
			return (1);
		bt->line[i][j] = '0';
	}
	bt->line[i][j] = 'x';
	dir = 0;
	while (dir < 4)
	{
		nij[0] = i;
		nij[1] = j;
		if (go_next(dir, nij, bt) != -1)
		{
			if (dfs_collect(nij[0], nij[1], bt))
				return (1);
		}
		dir++;
	}
	return (0);
}

static	int	go_next(int dir, int *nij, t_track *bt)
{
	if (dir == 0)
	{
		if (!(bt->line[nij[0] - 1][nij[1]] == '1')
			&& !(bt->line[nij[0] - 1][nij[1]] == 'x'))
			return (nij[0]--);
	}
	else if (dir == 1)
	{
		if (!(bt->line[nij[0]][nij[1] + 1] == '1')
			&& !(bt->line[nij[0]][nij[1] + 1] == 'x'))
			return (nij[1]++);
	}
	else if (dir == 2)
	{
		if (!(bt->line[nij[0] + 1][nij[1]] == '1')
			&& !(bt->line[nij[0] + 1][nij[1]] == 'x'))
			return (nij[0]++);
	}
	else if (dir == 3)
	{
		if (!(bt->line[nij[0]][nij[1] - 1] == '1')
			&& !(bt->line[nij[0]][nij[1] - 1] == 'x'))
			return (nij[1]--);
	}
	return (-1);
}
