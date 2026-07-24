/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 05:54:02 by vfreitas         #+#    #+#             */
/*   Updated: 2026/07/24 05:54:02 by vfreitas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
{
	int	i;
	int	id;

	id = 0;
	i = 0;
	while (i < a->size)
	{
		if(a->arr[i] < a->arr[id])
			id = i;
		i++;
	}
	return (id);
}

void	rotate(int i, void (*function)(t_stack *), t_stack *stack)
{
	while (i > 0)
	{
		function(stack);
		i--;
	}
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int min_pos;
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
		pa(a,b);
}