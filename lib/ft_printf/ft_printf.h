/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:20:00 by terabu            #+#    #+#             */
/*   Updated: 2022/11/03 13:54:14 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_printf_char(int *len, char c);
void	ft_printf_str(int *len, char *s);
void	ft_printf_int(int *len, int num);
void	ft_printf_uint(int *len, unsigned int num);
void	ft_printf_hex(int *len, unsigned int num, const char format);
void	ft_printf_pointer(int *len, unsigned long long num);
void	ft_printf_percent(int *len);

#endif
