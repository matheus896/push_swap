/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:17:20 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/16 19:57:53 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *s, int cap)
{
	s->arr = malloc(cap * sizeof(int));
	s->size = 0;
	s->cap = cap;
}

void	push(t_stack *s, int val)
{
	s->arr[s->size] = val;
	s->size++;
}
