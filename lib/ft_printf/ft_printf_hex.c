/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by terabu            #+#    #+#             */
/*   Updated: 2022/11/03 12:56:26 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex(int *len, unsigned int num, const char format)
{
	if (num == 0)
	{
		ft_printf_char(len, '0');
		return ;
	}
	if (num >= 16)
	{
		ft_printf_hex(len, num / 16, format);
		ft_printf_hex(len, num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_printf_char(len, num + '0');
		else
		{
			if (format == 'x')
				ft_printf_char(len, num - 10 + 'a');
			else
				ft_printf_char(len, num - 10 + 'A');
		}
	}
}
