/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:43:36 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/24 11:36:07 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X'
		|| c == '%');
}

int	ft_eval_format(va_list args, const char spec)
{
	if (spec == 'c')
		return (handle_char(args));
	if (spec == 's')
		return (handle_str(args));
	if (spec == 'p')
		return (handle_ptr(args));
	if (spec == 'd' || spec == 'i')
		return (handle_int(args));
	if (spec == 'u')
		return (handle_unsigned(args));
	if (spec == 'x')
		return (handle_hex(args, 0));
	if (spec == 'X')
		return (handle_hex(args, 1));
	if (spec == '%')
		return (handle_percent(args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	args;

	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && is_specifier(format[i + 1]))
		{
			printed += ft_eval_format(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			printed += ft_print_char(format[i]);
		else
			printed += ft_print_char('%');
		i++;
	}
	va_end(args);
	return (printed);
}
