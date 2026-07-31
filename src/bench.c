/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matalmei <matalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:00:00 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/31 16:16:05 by matalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *a)
{
	int	i;
	int	j;
	int	m;
	int	t;

	m = 0;
	t = 0;
	i = a->size - 1;
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			t++;
			if (a->arr[i] > a->arr[j])
				m++;
			j--;
		}
		i--;
	}
	if (t == 0)
		return (0);
	return ((int)(((long)m * 10000) / t));
}
