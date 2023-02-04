/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:31 by terabu            #+#    #+#             */
/*   Updated: 2023/02/04 12:28:13 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **line, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void	error_map(char **line, int row, const char *msg)
{
	free_array(line, row);
	print_error_msg(msg);
	exit(0);
}

// void	error_map(t_map *map, const char *msg)
// {
// 	free_array(map->line, map->row);
// 	print_error_msg(msg);
// 	exit(0);
// }

// void	error_playable(t_track *track, int row, const char *msg)
// {
// 	free_array(track->line, row);
// 	print_error_msg(msg);
// 	exit(0);
// }
