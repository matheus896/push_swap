/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:30:00 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/24 17:30:00 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_chunk(int v, int *sorted, int size, t_chunk *ck)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == v)
			return (i >= ck->min && i <= ck->max);
		i++;
	}
	return (0);
}

static int	find_max_pos(t_stack *b)
{
	int	i;
	int	max;
	int	pos;

	i = b->size - 1;
	max = b->arr[i];
	pos = 0;
	while (i >= 0)
	{
		if (b->arr[i] > max)
		{
			max = b->arr[i];
			pos = b->size - 1 - i;
		}
		i--;
	}
	return (pos);
}

static void	move_max_to_top(t_stack *b)
{
	int	pos;

	pos = find_max_pos(b);
	if (pos <= b->size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		pos = b->size - pos;
		while (pos--)
			rrb(b);
	}
}

static void	chunk_pass(t_stack *a, t_stack *b, int *sorted, t_chunk *ck)
{
	int	n;
	int	original;

	original = a->size + b->size;
	while (a->size > 0)
	{
		n = chunk_count(ck);
		while (n > 0)
		{
			if (is_chunk(a->arr[a->size - 1], sorted, original, ck))
			{
				pb(a, b);
				n--;
			}
			else
				ra(a);
		}
		if (ck->max == original - 1)
			break ;
		next_chunk(ck, original);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	t_chunk	ck;
	int		*sorted;
	int		total;

	total = a->size;
	sorted = malloc(sizeof(int) * total);
	if (!sorted)
		return ;
	cosort(a, sorted);
	init_chunk(&ck, total);
	chunk_pass(a, b, sorted, &ck);
	while (b->size > 0)
	{
		move_max_to_top(b);
		pa(a, b);
	}
	free(sorted);
}
