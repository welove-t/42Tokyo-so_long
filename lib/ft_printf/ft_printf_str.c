/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by terabu            #+#    #+#             */
/*   Updated: 2022/11/02 15:50:17 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(int *len, char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	ft_putstr_fd(s, 1);
	*len += ft_strlen(s);
}
