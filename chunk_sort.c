/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 06:00:37 by vfreitas          #+#    #+#             */
/*   Updated: 2026/07/24 06:00:37 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int number)
{
	int	i;

	if (number <= 0)
		return (0);
	i = 1;
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}

void	init_chunk(t_chunk *chunk, int stack_size)
{
	chunk->width = stack_size / ft_sqrt(stack_size);
	if (chunk->width == 0)
		chunk->width = 1;
	chunk->min = 0;
	chunk->max = chunk->width - 1;
}

void	next_chunk(t_chunk *chunk, int stack_size)
{
	chunk->min += chunk->width;
	chunk->max += chunk->width;
	if (chunk->max >= stack_size)
		chunk->max = stack_size - 1;
}

void	cosort(t_stack *a, int *cpy)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < a->size)
	{
		cpy[i] = a->arr[i];
		i++;
	}
	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (cpy[j] > cpy[j + 1])
			{
				tmp = cpy[j];
				cpy[j] = cpy[j + 1];
				cpy[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	is_chunk(int value, int *sorted, int size, t_chunk *chunk)
{
	int	rank;

	rank = 0;
	while (rank < size)
	{
		if (sorted[rank] == value)
			return (rank >= chunk->min && rank <= chunk->max);
		rank++;
	}
	return (0);
}

int chunk_count(t_chunk *chunk)
{
    return (chunk->max - chunk->min + 1);
}

int	find_max_pos(t_stack *b)
{
	int	i;
	int	max;
	int	pos;

	i = b->size - 1;
	max = b->arr[i];
	pos = 0;

	while (i >= 0)
	{
		if (b->arr[i] > max)
		{
			max = b->arr[i];
			pos = b->size - 1 - i;
		}
		i--;
	}
	return (pos);
}

void	move_max_to_top(t_stack *b)
{
	int	pos;

	pos = find_max_pos(b);

	if (pos <= b->size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		pos = b->size - pos;
		while (pos--)
			rrb(b);
	}
}

void	restore_stack(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	t_chunk chunk;
	int *sorted;
	int chunk_elements;
	int original_size;

	original_size = a->size;

	sorted = malloc(sizeof(int) * original_size);
	if (!sorted)
		return ;

	cosort(a, sorted);
	init_chunk(&chunk, original_size);

	while (a->size > 0)
	{
		chunk_elements = chunk_count(&chunk);

		while (chunk_elements > 0)
		{
			if (is_chunk(a->arr[a->size - 1],
					sorted, original_size, &chunk))
			{
				pb(a, b);
				chunk_elements--;
			}
			else
				ra(a);
		}

		if (chunk.max == original_size - 1)
			break ;

		next_chunk(&chunk, original_size);
	}

    restore_stack(a, b);
	free(sorted);
}

