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

void	ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->arr[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
	print_op("ra\n");
}

void	rb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	tmp = b->arr[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = tmp;
	print_op("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (a->size >= 2)
	{
		tmp = a->arr[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->arr[i] = a->arr[i - 1];
			i--;
		}
		a->arr[0] = tmp;
	}
	if (b->size >= 2)
	{
		tmp = b->arr[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->arr[i] = b->arr[i - 1];
			i--;
		}
		b->arr[0] = tmp;
	}
	print_op("rr\n");
}
