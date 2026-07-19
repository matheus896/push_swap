/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:37:16 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/19 09:47:27 by vfreitass        ###   ########.fr       */
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
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->arr[b->size - 1];
	b->arr[b->size - 1] = b->arr[b->size - 2];
	b->arr[b->size - 2] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	b->arr[b->size] = a->arr[a->size - 1];
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->arr[a->size] = b->arr[b->size - 1];
	b->size--;
	a->size++;
	write(1, "pa\n", 3);
}
