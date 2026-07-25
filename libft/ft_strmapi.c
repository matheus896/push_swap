/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:02:21 by matheusms1        #+#    #+#             */
/*   Updated: 2026/06/01 13:38:58 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*j;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	j = malloc(ft_strlen(s) + 1);
	if (j == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		j[i] = f(i, s[i]);
		i++;
	}
	j[i] = '\0';
	return (j);
}
