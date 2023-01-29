/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:34:22 by terabu            #+#    #+#             */
/*   Updated: 2022/11/03 14:45:42 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	percent_operate(int *len, va_list ap, const char format)
{
	if (format == 'c')
		ft_printf_char(len, va_arg(ap, int));
	else if (format == 's')
		ft_printf_str(len, va_arg(ap, char *));
	else if (format == 'p')
		ft_printf_pointer(len, (unsigned long long)va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		ft_printf_int(len, va_arg(ap, int));
	else if (format == 'u')
		ft_printf_uint(len, va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		ft_printf_hex(len, va_arg(ap, unsigned int), format);
	else if (format == '%')
		ft_printf_percent(len);
	else
		return ;
}

static int	normal_putstr(const char **format, const char **start)
{
	while (**format != '%' && **format)
		(*format)++;
	write(1, *start, *format - *start);
	return (*format - *start);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	const char	*start;

	len = 0;
	va_start(ap, format);
	if (format == NULL)
		len = -1;
	while (len >= 0 && *format != '\0')
	{
		start = format;
		if (*start != '%')
			len += normal_putstr(&format, &start);
		else
		{
			percent_operate(&len, ap, *++format);
			format++;
		}
	}
	va_end(ap);
	return (len);
}
