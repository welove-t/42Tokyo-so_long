/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by terabu            #+#    #+#             */
/*   Updated: 2022/11/03 13:02:22 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_hex(int *len, unsigned long long num)
{
	if (num >= 16)
	{
		printf_hex(len, num / 16);
		printf_hex(len, num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printf_char(len, num + '0');
		else
			ft_printf_char(len, num - 10 + 'a');
	}
}

void	ft_printf_pointer(int *len, unsigned long long num)
{
	ft_printf_str(len, "0x");
	if (num == 0)
	{
		ft_printf_char(len, '0');
		return ;
	}
	printf_hex(len, num);
}
