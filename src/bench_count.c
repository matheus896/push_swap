/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:00:00 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/25 18:35:28 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		g_ct[11];
static char		*g_nm[11];

void	bench_init()
{
	g_nm[0] = "sa";
	g_nm[1] = "sb";
	g_nm[2] = "ss";
	g_nm[3] = "pa";
	g_nm[4] = "pb";
	g_nm[5] = "ra";
	g_nm[6] = "rb";
	g_nm[7] = "rr";
	g_nm[8] = "rra";
	g_nm[9] = "rrb";
	g_nm[10] = "rrr";
}

void	bench_count(int op)
{
	g_ct[op]++;
}

static void	prt_strat(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		write(2, "simple (O(n^2))", 15);
	else if (s == STRAT_MEDIUM)
		write(2, "medium (O(n sqrt n))", 20);
	else if (s == STRAT_COMPLEX)
		write(2, "complex (O(n log n))", 20);
	else
		write(2, "adaptive", 8);
}

static void	prt_ops(void)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (g_ct[i] > 0)
		{
			write(2, g_nm[i], ft_strlen(g_nm[i]));
			write(2, ": ", 2);
			ft_putnbr_fd(g_ct[i], 2);
			write(2, "\n", 1);
		}
		i++;
	}
}

void	print_bench(t_strategy s, int d)
{
	int	t;
	int	i;

	t = 0;
	i = 0;
	bench_init();
	while (i < 11)
		t += g_ct[i++];
	write(2, "Disorder: ", 10);
	ft_putnbr_fd(d / 100, 2);
	write(2, ".", 1);
	if (d % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(d % 100, 2);
	write(2, "%\nStrategy: ", 12);
	prt_strat(s);
	write(2, "\nOperations: ", 13);
	ft_putnbr_fd(t, 2);
	write(2, "\n", 1);
	prt_ops();
}
