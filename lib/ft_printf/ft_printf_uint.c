/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by terabu            #+#    #+#             */
/*   Updated: 2022/11/03 13:48:44 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_uint(int *len, unsigned int num)
{
	if (num == 0)
	{
		ft_printf_char(len, '0');
		return ;
	}
	if (num >= 10)
	{
		ft_printf_uint(len, num / 10);
		ft_printf_uint(len, num % 10);
	}
	else
		ft_printf_char(len, num + '0');
}
