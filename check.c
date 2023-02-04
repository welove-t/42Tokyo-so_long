/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:12 by terabu            #+#    #+#             */
/*   Updated: 2023/02/04 16:03:11 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pre(int argc, char **argv)
{
	int		fd;
	char	*p;

	if (argc != 2)
	{
		print_error_msg(ERROR_ARGS);
		exit(0);
	}
	fd = open_file(argv[1]);
	close(fd);
	p = ft_strrchr(argv[1], '.');
	if (ft_strncmp(EXTENTION, p, 5))
	{
		print_error_msg(ERROR_BER);
		exit(0);
	}
}

void	check_map(t_map *map)
{
	int		y;
	int		row_cnt;

	y = 0;
	map->col = ft_strlen(map->line[y + map->start_row]) - 1;
	row_cnt = 0;
	while (y + map->start_row <= map->end_row)
	{
		if (!ft_strncmp(map->line[y + map->start_row], "\n", 1))
			error_map(map->line, map->row, ERROR_CLOSEMAP);
		check_rect_wall(map->line[y + map->start_row], map, y);
		check_item(map->line[y + map->start_row], map, y);
		y++;
	}
}

void	check_rect_wall(char *s, t_map *map, int y)
{
	size_t	i;

	if (map->col != ft_strlen(s) - 1)
		error_map(map->line, map->row, ERROR_RECT);
	if (y == 0 || y == map->end_row)
	{
		i = 0;
		while (s[i] != '\n')
		{
			if (s[i] != '1')
				error_map(map->line, map->row, ERROR_WALL);
			i++;
		}
	}
	else
	{
		if (s[0] != '1' || s[map->col - 1] != '1')
			error_map(map->line, map->row, ERROR_WALL);
	}
}

void	check_item(char *s, t_map *map, int y)
{
	static int	i_cnt[2];

	while (*s != '\n')
	{
		if (*s != '1' && *s != '0' && *s != 'C'
			&& *s != 'E' && *s != 'P')
			error_map(map->line, map->row, ERROR_ITEM);
		else if (*s == 'C')
			map->c_cnt += 1;
		else if (*s == 'E')
			i_cnt[0] += 1;
		else if (*s == 'P')
			i_cnt[1] += 1;
		s++;
	}
	if (y == map->end_row)
	{
		if (map->c_cnt == 0)
			error_map(map->line, map->row, ERROR_COLLECT);
		if (i_cnt[0] != 1)
			error_map(map->line, map->row, ERROR_GOAL);
		if (i_cnt[1] != 1)
			error_map(map->line, map->row, ERROR_PLAYER);
	}
}
