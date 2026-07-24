/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:53:14 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/21 16:58:19 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->arr[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = tmp;
}

void	ra(t_stack *a)
{
	rot(a);
	print_op("ra\n");
	bench_count(OP_RA);
}

void	rb(t_stack *b)
{
	rot(b);
	print_op("rb\n");
	bench_count(OP_RB);
}

void	rr(t_stack *a, t_stack *b)
{
	rot(a);
	rot(b);
	print_op("rr\n");
	bench_count(OP_RR);
}
