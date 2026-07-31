/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:00:00 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/21 16:41:18 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_dispatch(t_stack *a, t_stack *b)
{
	int	d;

	if (a->size <= 3)
		sort_3(a);
	else if (a->size <= 5)
		selection_sort(a, b);
	else
	{
		d = compute_disorder(a);
		if (d < 2000)
			selection_sort(a, b);
		else if (d < 5000)
			chunk_sort(a, b);
		else
			binary_radix(a, b);
	}
}

void	dispatch(t_stack *a, t_stack *b, t_strategy strategy, int bench_mode)
{
	(void)bench_mode;
	if (is_sorted(a))
		return ;
	if (strategy == STRAT_SIMPLE)
		selection_sort(a, b);
	else if (strategy == STRAT_MEDIUM)
		chunk_sort(a, b);
	else if (strategy == STRAT_COMPLEX)
		binary_radix(a, b);
	else if (strategy == STRAT_ADAPTIVE)
		adaptive_dispatch(a, b);
}
