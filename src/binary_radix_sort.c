/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:36:47 by vfreitas          #+#    #+#             */
/*   Updated: 2026/07/24 17:36:47 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bin_size(int size)
{
	int	count;

	count = 0;
	while (size > 0)
	{
		size /= 2;
		count++;
	}
	return (count);
}

int	stack_index_rank(int *sorted, int v, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == v)
			return (i);
		i++;
	}
	return (0);
}

static void	radix_pass(t_stack *a, t_stack *b, int *sorted, int bit)
{
	int	total;
	int	size;
	int	i;

	total = a->size + b->size;
	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((stack_index_rank(sorted, a->arr[a->size - 1], total) >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	binary_radix(t_stack *a, t_stack *b)
{
	int		*sorted;
	int		total;
	int		max_bin;
	int		bit;

	total = a->size;
	sorted = malloc(sizeof(int) * total);
	if (!sorted)
		return ;
	cosort(a, sorted);
	max_bin = bin_size(total - 1);
	bit = 0;
	while (bit < max_bin)
	{
		radix_pass(a, b, sorted, bit);
		bit++;
	}
	free(sorted);
}
