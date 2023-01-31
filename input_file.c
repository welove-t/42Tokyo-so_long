/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:21:01 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 09:37:12 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_file(t_solong *map)
{
	int		i;

	map->filepath = "./map/1.ber";
	get_ncount(map);
	map->fd = open(map->filepath, O_RDONLY);
	map->line = malloc(sizeof(char *) * map->row);
	i = 0;
	while (i < map->row)
	{
		map->line[i] = get_next_line(map->fd);
		if (i == 0)
			map->col = ft_strlen(map->line[i]) - 1;
		i++;
	}
}

void	get_ncount(t_solong *map)
{
	int		cnt;

	map->fd = open(map->filepath, O_RDONLY);
	cnt = 0;
	while (get_next_line(map->fd))
		cnt++;
	map->row = cnt;
}
