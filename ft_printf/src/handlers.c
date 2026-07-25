/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matalmei <matalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:13:04 by matheusms1        #+#    #+#             */
/*   Updated: 2026/06/29 17:18:28 by matalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	return (ft_print_str(str));
}

int	handle_ptr(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_print_str("(nil)"));
	if (ft_print_str("0x") == -1)
		return (-1);
	return (2 + ft_print_nbr((unsigned long)ptr, 16, 0));
}

int	handle_int(va_list args)
{
	long	n;
	int		printed;

	printed = 0;
	n = va_arg(args, int);
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		printed++;
		n = -n;
	}
	printed += ft_print_nbr((unsigned long)n, 10, 0);
	return (printed);
}

int	handle_unsigned(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_print_nbr((unsigned long)n, 10, 0));
}

int	handle_hex(va_list args, int upper)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_print_nbr((unsigned long)n, 16, upper));
}
