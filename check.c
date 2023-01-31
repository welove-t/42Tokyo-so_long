/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:12 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 14:01:07 by terabu           ###   ########.fr       */
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
