/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:21:01 by terabu            #+#    #+#             */
/*   Updated: 2023/02/04 16:11:07 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_file(t_map *map, char *filepath)
{
	int		i;

	map->filepath = filepath;
	get_ncount(map);
	if (!(map->row))
	{
		print_error_msg(ERROR_EMPTY);
		exit(0);
	}
	map->fd = open_file(map->filepath);
	map->line = malloc(sizeof(char *) * map->row);
	map->c_cnt = 0;
	i = 0;
	while (i < map->row)
	{
		map->line[i] = get_next_line(map->fd);
		i++;
	}
	set_map_row(map);
}

void	get_ncount(t_map *map)
{
	int		cnt;
	char	*s;

	map->fd = open_file(map->filepath);
	cnt = 0;
	s = get_next_line(map->fd);
	while (s)
	{
		cnt++;
		if (ft_strlen(s) > MAX_COL || cnt > MAX_ROW)
		{
			free(s);
			close(map->fd);
			print_error_msg(ERROR_BIG_MAP);
			exit(0);
		}
		free(s);
		s = get_next_line(map->fd);
	}
	map->row = cnt;
	close(map->fd);
}

void	set_map_row(t_map *map)
{
	int	i;

	i = 0;
	while (!ft_strncmp(map->line[i], "\n", 1))
		i++;
	map->start_row = i;
	i = map->row - 1;
	while (!ft_strncmp(map->line[i], "\n", 1) && i >= 0)
		i--;
	map->end_row = i;
}

void	set_map_to_solong(t_map *map, t_solong *sl)
{
	int	y;
	int	size;

	y = 0;
	size = map->end_row - map->start_row + 1;
	sl->line = malloc(sizeof(char *) * size);
	while (y + map->start_row <= map->end_row)
	{
		sl->line[y] = ft_strdup(map->line[y + map->start_row]);
		y++;
	}
	sl->row = size;
	sl->col = map->col;
	sl->c_cnt = map->c_cnt;
	free_array(map->line, map->row);
}

int	open_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		print_error_msg(ERROR_FILE);
		exit(0);
	}
	return (fd);
}
// void	set_solong_to_bt(t_solong *sl)
// {

// }
// char	*gnl_skip_n(int fd)
// {
// 	char	*tmp;

// 	tmp = get_next_line(fd);
// 	while (!ft_strncmp(tmp, "\n", 1))
// 	{
// 		free(tmp);
// 		tmp = get_next_line(fd);
// 	}
// 	return (tmp);
// }
