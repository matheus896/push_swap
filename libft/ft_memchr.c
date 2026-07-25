/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:17:06 by matheusms1        #+#    #+#             */
/*   Updated: 2026/06/17 07:33:58 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		j;
	size_t				i;

	ptr = s;
	j = c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == j)
			return ((unsigned char *) &ptr[i]);
		i++;
	}
	return (NULL);
}
