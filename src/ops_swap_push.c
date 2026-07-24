/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:37:16 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/24 13:28:40 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->arr[a->size - 1];
	a->arr[a->size - 1] = a->arr[a->size - 2];
	a->arr[a->size - 2] = tmp;
	print_op("sa\n");
	bench_count(OP_SA);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->arr[b->size - 1];
	b->arr[b->size - 1] = b->arr[b->size - 2];
	b->arr[b->size - 2] = tmp;
	print_op("sb\n");
	bench_count(OP_SB);
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->arr[a->size - 1];
		a->arr[a->size - 1] = a->arr[a->size - 2];
		a->arr[a->size - 2] = tmp;
	}
	if (b->size >= 2)
	{
		tmp = b->arr[b->size - 1];
		b->arr[b->size - 1] = b->arr[b->size - 2];
		b->arr[b->size - 2] = tmp;
	}
	print_op("ss\n");
	bench_count(OP_SS);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	b->arr[b->size] = a->arr[a->size - 1];
	a->size--;
	b->size++;
	print_op("pb\n");
	bench_count(OP_PB);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->arr[a->size] = b->arr[b->size - 1];
	b->size--;
	a->size++;
	print_op("pa\n");
	bench_count(OP_PA);
}
