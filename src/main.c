/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:03:21 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/24 12:03:53 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	*operation_counter(void)
{
	static size_t	counter;

	return (&counter);
}

void	print_op(char *op)
{
	ft_strlen(op);
	//write(1, op, ft_strlen(op));
	(*operation_counter())++;
}

void	print_stack(t_stack *stack, char *name)
{
	int	i;

	printf("%s\n", name);
	printf("-----\n");

	i = stack->size - 1;
	while (i >= 0)
	{
		printf("%d\n", stack->arr[i]);
		i--;
	}

	printf("-----\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);

	if (!parse_args(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	init(&b, a.cap);

	//printf("ANTES:\n");
	//print_stack(&a, "A");
	//print_stack(&b, "B");

	//chunk_sort(&a, &b);
	selection_sort(&a, &b);

	//printf("\nDEPOIS:\n");
	//print_stack(&a, "A");
	//print_stack(&b, "B");

	printf("Numero op: %zu\n", *operation_counter());
	free(a.arr);
	free(b.arr);

	return (0);
}

/*int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	int			bench_mode;
	int			disorder;

	if (argc < 2)
		return (0);
	strategy = detect_strategy(argc, argv, &bench_mode);
	if (!parse_args(argc, argv, &a))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	init(&b, a.cap);
	if (bench_mode)
		disorder = compute_disorder(&a);
	dispatch(&a, &b, strategy, bench_mode);
	if (bench_mode)
		print_bench(strategy, disorder);
	free(a.arr);
	free(b.arr);
	return (0);
}
*/