/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:37:34 by matheusms1        #+#    #+#             */
/*   Updated: 2026/06/19 18:35:02 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	if (num == 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill(char *c, long num, int len)
{
	int	i;
	int	start;

	i = len - 1;
	start = 0;
	if (num < 0)
	{
		c[0] = '-';
		num = -num;
		start = 1;
	}
	while (i >= start)
	{
		c[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	char	*c;
	int		len;

	num = n;
	len = ft_len(num);
	c = malloc(len + 1);
	if (c == NULL)
		return (NULL);
	c[len] = '\0';
	ft_fill(c, num, len);
	return (c);
}
