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
	chunk->width = ft_sqrt(stack_size);
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

int	chunk_count(t_chunk *chunk)
{
	return (chunk->max - chunk->min + 1);
}

int	find_chunk_pos(t_stack *a, int *sorted, int size, t_chunk *chunk)
{
	int	top;
	int	bottom;

	top = 0;
	while (top < a->size)
	{
		if (is_chunk(a->arr[a->size - 1 - top],
				sorted, size, chunk))
			break ;
		top++;
	}

	bottom = 0;
	while (bottom < a->size)
	{
		if (is_chunk(a->arr[bottom],
				sorted, size, chunk))
			break ;
		bottom++;
	}

	if (top == a->size && bottom == a->size)
		return (0);

	if (top == 0)
		return (0);

	if (top <= bottom)
		return (top);

	return (-(bottom + 1));
}

void	process_chunk(t_stack *a, t_stack *b, int *sorted,
		int original_size, t_chunk *chunk)
{
	int	count;
	int	pos;

	count = chunk_count(chunk);

	while (count > 0)
	{
		pos = find_chunk_pos(a, sorted, original_size, chunk);

		if (pos > 0)
		{
			while (pos--)
				ra(a);
		}
		else if (pos < 0)
		{
			pos = (-pos) - 1;
			while (pos--)
				rra(a);
		}

		pb(a, b);
		count--;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	t_chunk	chunk;
	int		*sorted;
	int		original_size;

	original_size = a->size;

	sorted = malloc(sizeof(int) * original_size);
	if (!sorted)
		return ;

	cosort(a, sorted);
	init_chunk(&chunk, original_size);

	while (a->size > 0)
	{
		process_chunk(a, b, sorted, original_size, &chunk);

		if (chunk.max == original_size - 1)
			break ;

		next_chunk(&chunk, original_size);
	}

	free(sorted);
}