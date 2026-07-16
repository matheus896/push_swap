/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:18:44 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/16 20:17:20 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	cap;
}	t_stack;

void	init(t_stack *s, int cap);
void	push(t_stack *s, int val);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	sort_3(t_stack *a, t_stack *b);

#endif