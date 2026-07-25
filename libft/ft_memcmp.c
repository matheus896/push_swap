/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:52:44 by matheusms1        #+#    #+#             */
/*   Updated: 2026/06/22 10:50:44 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1;
    const unsigned char *p2;
    size_t i;

    p1 = s1;
    p2 = s2;
    i = 0;
    if (n == 0)
      return (0);
    while(i < n)
    {
        if (p1[i] != p2[i])
            return (p1[i] - p2[i]);
        i++;
    }
    return (0);
}

// int	main(void)
// {
// 	printf("a diferenca e: %d\n", ft_memcmp("abC", "abd", 4));
// 	return (0);
// }
