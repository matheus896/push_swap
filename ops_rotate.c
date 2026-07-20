/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:53:14 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/20 17:09:11 by matheusms1       ###   ########.fr       */
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->size - 1] = tmp;
	write(1, "rra\n", 5);
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	tmp = b->arr[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->size - 1] = tmp;
	write(1, "rrb\n", 5);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (a->size >= 2)
	{
		tmp = a->arr[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->arr[i] = a->arr[i + 1];
			i++;
		}
		a->arr[a->size - 1] = tmp;
	}
	if (b->size >= 2)
	{
		tmp = b->arr[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->arr[i] = b->arr[i + 1];
			i++;
		}
		b->arr[b->size - 1] = tmp;
	}
	write(1, "rrr\n", 4);
}
