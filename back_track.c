/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:18:41 by terabu            #+#    #+#             */
/*   Updated: 2023/02/04 12:43:50 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	go_next(int dir, size_t *nij, t_track *bt);

int	dfs_goal(int i, size_t j, t_track *bt)
{
	int		dir;
	size_t	nij[2];

	if (bt->line[i][j] == 'E')
		return (1);
	bt->line[i][j] = 'x';
	dir = 0;
	while (dir < 4)
	{
		nij[0] = (size_t)i;
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

int	dfs_collect(int i, size_t j, t_track *bt)
{
	int		dir;
	size_t	nij[2];

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
		nij[0] = (size_t)i;
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

// for (int s = 0; s < 5; s++)
// 	printf("%s", bt->line[s]);
// putchar('\n');


// int	dfs_goal(int i, size_t j, t_track *bt, int *dic)
// {
// 	int	dir;

// 	printf("point(%zu, %d)\n",j, i);
// 	for (int s = 0; s < 5; s++)
// 		printf("%s", bt->line[s]);
// 	if (bt->line[i][j] == 'E')
// 		return (1);
// 	dir = 0;
// 	bt->line[i][j] = 'x';
// 	while (dir < 4)
// 	{
// 		printf("  dic: %d %d %d %d\n", dic[0], dic[1], dic[2], dic[3]);
// 		if (can_go(dir, (size_t)i, j, bt) && dic[dir] != 1)
// 		{
// 			go_next(dir, &i, &j, dic);
// 			if (dfs_goal(i, j, bt, dic))
// 				return (1);
// 		}
// 		dir++;
// 	}
// 	bt->line[i][j] = '0';
// 	init_dic(dic);
// 	return (0);
// }

// int	dfs_collect(int i, size_t j, t_track *bt, int *dic)
// {
// 	int	dir;

// 	// printf("point(%zu, %d)\n",j, i);
// 	if (bt->line[i][j] == 'C')
// 	{
// 		bt->x = j;
// 		bt->y = i;
// 		return (1);
// 	}
// 	dir = 0;
// 	while (dir < 4)
// 	{
// 		// printf("  dic: %d %d %d %d\n", dic[0], dic[1], dic[2], dic[3]);
// 		if (can_go(dir, (size_t)i, j, bt) && dic[dir] != 1)
// 		{
// 			if (dfs_collect(i, j, bt, dic))
// 				return (1);
// 		}
// 		dir++;
// 	}
// 	bt->line[i][j] = 'x';
// 	init_dic(dic);
// 	return (0);
// }

static	int	go_next(int dir, size_t *nij, t_track *bt)
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
