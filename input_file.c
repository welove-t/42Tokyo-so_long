/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:21:01 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 11:12:44 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_file(t_map *map)
{
	int		i;

	printf("hoge\n");
	map->filepath = "./map/1.ber";
	get_ncount(map);
	map->fd = open(map->filepath, O_RDONLY);
	map->line = malloc(sizeof(char *) * map->row);
	i = 0;
	while (i < map->row)
	{
		map->line[i] = get_next_line(map->fd);
		i++;
	}
}

void	get_ncount(t_map *map)
{
	int		cnt;

	map->fd = open(map->filepath, O_RDONLY);
	cnt = 0;
	while (get_next_line(map->fd))
		cnt++;
	map->row = cnt;
}
