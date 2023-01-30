/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:21:01 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 09:11:59 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**input_file(void)
{
	int		fd;
	int		i;
	int		ncount;
	char	*filepath;
	char	**line = NULL;

	ncount = get_ncount();
	filepath = "./map/1.ber";
	fd = open(filepath, O_RDONLY);
	line = malloc(sizeof(char *) * ncount);
	i = 0;
	while (i < ncount)
	{

		line[i] = get_next_line(fd);
		i++;
	}
	return (line);
}

int	get_ncount(void)
{
	int		cnt;
	int		fd;
	char	*filepath;

	filepath = "./map/1.ber";
	fd = open(filepath, O_RDONLY);
	cnt = 0;
	while (get_next_line(fd))
		cnt++;
	return (cnt);
}
