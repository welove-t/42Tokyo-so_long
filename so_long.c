/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by terabu            #+#    #+#             */
/*   Updated: 2023/01/29 16:01:00 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

int main()
{
	char	*line;

	line = imput_file();
	printf("%s\n", line);
}

// gcc -lmlx -framework OpenGL -framework AppKit so_long.c
