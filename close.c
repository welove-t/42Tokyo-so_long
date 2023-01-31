/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:47:31 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 15:32:38 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(t_solong *sl)
{
	int	i;

	i = 0;
	while (i < sl->row)
	{
		free(sl->line[i]);
		i++;
	}
	free(sl->line);
}

void	check_error_map(char *s, int fd, const char *msg)
{
	free(s);
	close(fd);
	print_error_msg(msg);
	exit(0);
}
