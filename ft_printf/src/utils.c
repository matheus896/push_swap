/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matalmei <matalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:13:04 by matheusms1        #+#    #+#             */
/*   Updated: 2026/06/29 17:18:54 by matalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_print_char(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(unsigned long n, int base, int upper)
{
	int		count;
	char	*digits;

	count = 0;
	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= (unsigned long)base)
		count += ft_print_nbr(n / base, base, upper);
	count += ft_print_char(digits[n % base]);
	return (count);
}

int	handle_char(va_list args)
{
	return (ft_print_char(va_arg(args, int)));
}

int	handle_percent(va_list args)
{
	(void)args;
	return (ft_print_char('%'));
}
