/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:00:00 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/20 18:09:37 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch(t_stack *a, t_stack *b, t_strategy strategy, int bench_mode)
{
	(void)strategy;
	(void)bench_mode;
	sort_3(a, b);
}
