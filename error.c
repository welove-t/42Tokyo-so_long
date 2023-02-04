/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:00 by terabu            #+#    #+#             */
/*   Updated: 2023/02/04 16:35:06 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char **line, int row, const char *msg)
{
	free_array(line, row);
	exit_error(msg);
}

void	error_file(int fd, char *s, const char *msg)
{
	free(s);
	close(fd);
	exit_error(msg);
}

void	error_malloc_array(char **s, int i)
{
	free_array(s, i);
	exit_error(ERROR_MALLOC);
}
