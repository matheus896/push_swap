/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:32:35 by matheusms1        #+#    #+#             */
/*   Updated: 2026/05/28 21:42:20 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	c;

	i = n;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	c = i % 10 + '0';
	write(fd, &c, 1);
}
