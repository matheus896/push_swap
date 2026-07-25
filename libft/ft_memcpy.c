/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:05:38 by matheusms1        #+#    #+#             */
/*   Updated: 2026/06/07 08:24:25 by matheusms1       ###   ########.fr       */
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
