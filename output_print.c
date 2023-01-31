/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:05:20 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 13:49:28 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move_cnt(t_solong *sl)
{
	ft_printf("move-count:%d\n", ++sl->m_cnt);
}

void	print_error_msg(char const *message)
{
	ft_printf("ERROR\n");
	ft_printf(" --> %s\n", message);
}
