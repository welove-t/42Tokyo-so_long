/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:12 by terabu            #+#    #+#             */
/*   Updated: 2023/02/01 10:43:10 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pre(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		print_error_msg(ERROR_ARGS);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error_msg(ERROR_FILE);
		exit(0);
	}
	close(fd);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
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
		printf("%s\n", map->line[y + map->start_row]);
		if (!ft_strncmp(map->line[y + map->start_row], "\n", 1))
			error_map(map, ERROR_CLOSEMAP);
		check_rect_wall(map->line[y + map->start_row], map, y);
		check_item(map->line[y + map->start_row], map, y);
		y++;
	}
}

void	check_rect_wall(char *s, t_map *map, int y)
{
	size_t	i;

	if (map->col != ft_strlen(s) - 1)
		error_map(map, ERROR_RECT);
	if (y == 0 || y == map->end_row)
	{
		i = 0;
		while (s[i] != '\n')
		{
			if (s[i] != '1')
				error_map(map, ERROR_WALL);
			i++;
		}
	}
	else
	{
		if (s[0] != '1' || s[map->col - 1] != '1')
			error_map(map, ERROR_WALL);
	}
}

void	check_item(char *s, t_map *map, int y)
{
	static int	i_cnt[3];

	while (*s != '\n')
	{
		if (*s != '1' && *s != '0' && *s != 'C'
			&& *s != 'E' && *s != 'P')
			error_map(map, ERROR_ITEM);
		else if (*s == 'C')
			i_cnt[0] += 1;
		else if (*s == 'E')
			i_cnt[1] += 1;
		else if (*s == 'P')
			i_cnt[2] += 1;
		s++;
	}
	if (y == map->end_row)
	{
		if (i_cnt[0] == 0)
			error_map(map, ERROR_COLLECT);
		if (i_cnt[1] != 1)
			error_map(map, ERROR_GOAL);
		if (i_cnt[2] != 1)
			error_map(map, ERROR_PLAYER);
	}
}
