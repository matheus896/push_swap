/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:00:00 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/21 17:05:13 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	int	i;
	int	id;

	id = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[id])
			id = i;
		i++;
	}
	return (id);
}

static void	rotate(int i, void (*f)(t_stack *), t_stack *stack)
{
	while (i > 0)
	{
		f(stack);
		i--;
	}
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	ra_cost;
	int	rra_cost;

	while (a->size > 1)
	{
		min_pos = find_min(a);
		ra_cost = (a->size - 1) - min_pos;
		rra_cost = min_pos + 1;
		if (ra_cost <= rra_cost)
			rotate(ra_cost, ra, a);
		else
			rotate(rra_cost, rra, a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
