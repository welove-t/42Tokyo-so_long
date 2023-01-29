/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by terabu            #+#    #+#             */
/*   Updated: 2022/11/03 13:40:45 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_int(int *len, int num)
{
	long	lnum;

	ft_putnbr_fd(num, 1);
	lnum = (long)num;
	if (lnum <= 0)
	{
		*len += 1;
		lnum *= -1;
	}
	while (lnum)
	{
		lnum /= 10;
		*len += 1;
	}
}
