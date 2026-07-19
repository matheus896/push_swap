/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:03:21 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/19 12:50:37 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		val;

	if (argc < 2)
		return (0);
	init(&a, 3);
	init(&b, 3);
	i = argc - 1;
	while (i >= 1)
	{
		val = atoi(argv[i]); //trocar para ft_atoi depois
		push(&a, val);
		i--;
	}
	sort_3(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}
