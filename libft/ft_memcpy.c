/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matalmei <matalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:05:38 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/25 16:28:53 by matalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*source;
	size_t				i;

	i = 0;
	des = dest;
	source = src;
	while (i < n)
	{
		des[i] = source[i];
		i++;
	}
	return (des);
}
