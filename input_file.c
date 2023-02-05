/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:21:01 by terabu            #+#    #+#             */
/*   Updated: 2023/02/05 14:58:35 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_file(t_map *map, char *filepath)
{
	int		i;

	map->filepath = filepath;
	get_ncount(map);
	if (!(map->row))
		exit_error(ERROR_EMPTY);
	map->fd = open_file(map->filepath);
	map->line = malloc(sizeof(char *) * map->row);
	if (map->line == NULL)
		exit_error(ERROR_MALLOC);
	map->c_cnt = 0;
	i = 0;
	while (i < map->row)
	{
		map->line[i] = get_next_line(map->fd);
		if (map->line[i] == NULL)
			error_malloc_array(map->line, i);
		i++;
	}
	set_map_row(map);
}

void	get_ncount(t_map *map)
{
	int		buf_size;
	char	*buf;

	map->fd = open_file(map->filepath);
	buf_size = (MAX_FILE_ROW + 1) * (MAX_MAP_COL + 1);
	buf = malloc(sizeof(char) * buf_size);
	if (buf == NULL)
		exit_error(ERROR_MALLOC);
	if (read(map->fd, buf, buf_size) == -1)
		exit_error(ERROR_READ);
	set_nrow_check_map_size(buf, &map->row);
	free(buf);
	close(map->fd);
}

void	set_map_row(t_map *map)
{
	int	i;

	i = 0;
	while (!ft_strncmp(map->line[i], "\n", 1))
	{
		i++;
		if (i >= map->row)
			error_map(map->line, map->row, ERROR_EMPTY);
	}
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
	if (sl->line == NULL)
		exit_error(ERROR_MALLOC);
	while (y + map->start_row <= map->end_row)
	{
		sl->line[y] = ft_strdup(map->line[y + map->start_row]);
		if (sl->line[y] == NULL)
		{
			free_array(map->line, map->row);
			error_malloc_array(sl->line, y);
		}
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
