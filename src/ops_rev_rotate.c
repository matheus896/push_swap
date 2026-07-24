/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:54:33 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/21 16:57:07 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revrot(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->arr[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->size - 1] = tmp;
}

void	rra(t_stack *a)
{
	revrot(a);
	write(1, "rra\n", 4);
	bench_count(OP_RRA);
}

void	rrb(t_stack *b)
{
	revrot(b);
	write(1, "rrb\n", 4);
	bench_count(OP_RRB);
}

void	rrr(t_stack *a, t_stack *b)
{
	revrot(a);
	revrot(b);
	write(1, "rrr\n", 4);
	bench_count(OP_RRR);
}
