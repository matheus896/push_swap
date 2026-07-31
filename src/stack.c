/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitas <vfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:17:20 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/31 15:08:49 by vfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *s, int cap)
{
	s->arr = malloc(cap * sizeof(int));
	s->cap = cap;
	s->size = 0;
	if (!s->arr)
		return ;
}

void	push(t_stack *s, int val)
{
	s->arr[s->size] = val;
	s->size++;
}
