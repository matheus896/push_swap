/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:57:42 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/21 07:14:03 by vfreitass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->arr[a->size - 1] > a->arr[a->size - 2])
		sa(a);
	if (a->arr[0] < a->arr[1])
		rra(a);
	if (a->arr[a->size - 1] > a->arr[a->size - 2])
		sa(a);
}
