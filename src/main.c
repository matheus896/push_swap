/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:03:21 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/31 15:04:11 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
}

int	main(int argc, char **argv)
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
