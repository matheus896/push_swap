/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:37:04 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/20 18:25:35 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	detect_strategy(int argc, char **argv, int *bench_mode)
{
	int		i;
	int		strat;

	*bench_mode = 0;
	strat = STRAT_ADAPTIVE;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (strcmp(argv[i] + 2, "bench") == 0)
				*bench_mode = 1;
			else if (strcmp(argv[i] + 2, "simple") == 0)
				strat = STRAT_SIMPLE;
			else if (strcmp(argv[i] + 2, "medium") == 0)
				strat = STRAT_MEDIUM;
			else if (strcmp(argv[i] + 2, "complex") == 0)
				strat = STRAT_COMPLEX;
			else if (strcmp(argv[i] + 2, "adaptive") == 0)
				strat = STRAT_ADAPTIVE;
		}
		i++;
	}
	return (strat);
}
