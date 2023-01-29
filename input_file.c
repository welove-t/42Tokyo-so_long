/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:21:01 by terabu            #+#    #+#             */
/*   Updated: 2023/01/30 06:51:47 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	*input_file(void)
{
	int		fd;
	char	*filepath;
	char	*line;

	filepath = "./map/1.ber";
	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	return (line);
}
