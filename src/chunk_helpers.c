/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:30:00 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/24 12:08:30 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i - 1);
}

void	init_chunk(t_chunk *ck, int size)
{
	ck->width = size / ft_sqrt(size);
	if (ck->width == 0)
		ck->width = 1;
	ck->min = 0;
	ck->max = ck->width - 1;
}

void	next_chunk(t_chunk *ck, int size)
{
	ck->min += ck->width;
	ck->max += ck->width;
	if (ck->max >= size)
		ck->max = size - 1;
}

int	chunk_count(t_chunk *ck)
{
	return (ck->max - ck->min + 1);
}

void	cosort(t_stack *a, int *cpy)
{
	int	i;
	int	j;
	int	t;

	i = -1;
	while (++i < a->size)
		cpy[i] = a->arr[i];
	i = -1;
	while (++i < a->size - 1)
	{
		j = -1;
		while (++j < a->size - i - 1)
		{
			if (cpy[j] > cpy[j + 1])
			{
				t = cpy[j];
				cpy[j] = cpy[j + 1];
				cpy[j + 1] = t;
			}
		}
	}
}
