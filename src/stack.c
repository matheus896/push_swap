/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:17:20 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/31 12:03:40 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *s, int cap)
{
	s->arr = malloc(cap * sizeof(int));
	s->cap = cap;
	s->size = 0;
	if (!s->arr)
		return ;
}

void	push(t_stack *s, int val)
{
	s->arr[s->size] = val;
	s->size++;
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
