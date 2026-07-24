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

int find_chunk_pos(t_stack *a, int *sorted, int size, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (is_chunk(a->arr[a->size - 1 - i], sorted, size, chunk))
			return (i);
		i++;
	}
	return (-1);
}

int chunk_count(t_chunk *chunk)
{
    return (chunk->max - chunk->min + 1);
}

void    chunk_sort(t_stack *a, t_stack *b)
{
    t_chunk chunk;
    int *sorted;
    int i;
    int	pos;
    int original_size;

    original_size = a->size;
    sorted = malloc(sizeof(int) * original_size);
    
    cosort(a, sorted);
    init_chunk(&chunk, original_size);

    while (a->size)
    {
        i = 0;

        while (i < chunk_count(&chunk))
        {
            pos = find_chunk_pos(a, sorted, original_size, &chunk);

            if (pos == 0)
            {
                pb(a, b);
                i++;
            }
            else if (pos <= a->size / 2)
                ra(a);
            else
                rra(a);
        }
        next_chunk(&chunk, original_size);
    }
    free(sorted);
}