/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:18:41 by terabu            #+#    #+#             */
/*   Updated: 2023/02/03 13:40:48 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	can_go(int dir, size_t i, size_t j, t_track *bt);
static void	go_next(int dir, int *i, size_t *j, int *dic);

int	dfs(int i, size_t j, t_track *bt, int *dic)
{
	int	dir;

	// printf("point(%zu, %d)\n",j, i);
	if (bt->line[i][j] == 'E')
		return (1);
	dir = 0;
	while (dir < 4)
	{
		// printf("  dic: %d %d %d %d\n", dic[0], dic[1], dic[2], dic[3]);
		if (can_go(dir, (size_t)i, j, bt) && dic[dir] != 1)
		{
			go_next(dir, &i, &j, dic);
			if (dfs(i, j, bt, dic))
				return (1);
		}
		dir++;
	}
	bt->line[i][j] = 'x';
	init_dic(dic);
	return (0);
}

static bool	can_go(int dir, size_t i, size_t j, t_track *bt)
{
	// printf("  wdsa:%d\n", dir);
	if (dir == 0)
	{
		if (bt->line[i - 1][j] == '1')
			return (false);
	}
	if (dir == 1)
	{
		if (bt->line[i][j + 1] == '1')
			return (false);
	}
	if (dir == 2)
	{
		if (bt->line[i + 1][j] == '1')
			return (false);
	}
	if (dir == 3)
	{
		if (bt->line[i][j - 1] == '1')
			return (false);
	}
	return (true);
}

static	void	go_next(int dir, int *i, size_t *j, int *dic)
{
	if (dir == 0)
	{
		(*i)--;
		dic[2] = 1;
	}
	else if (dir == 1)
	{
		(*j)++;
		dic[3] = 1;
	}
	else if (dir == 2)
	{
		(*i)++;
		dic[0] = 1;
	}
	else if (dir == 3)
	{
		(*j)--;
		dic[1] = 1;
	}
}
