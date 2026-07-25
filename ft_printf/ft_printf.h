/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:00:05 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/24 11:36:15 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(unsigned long n, int base, int upper);
int	handle_char(va_list args);
int	handle_percent(va_list args);
int	handle_str(va_list args);
int	handle_ptr(va_list args);
int	handle_int(va_list args);
int	handle_unsigned(va_list args);
int	handle_hex(va_list args, int upper);

#endif
