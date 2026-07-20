/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:18:44 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/20 18:14:24 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	cap;
}	t_stack;

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

void	init(t_stack *s, int cap);
void	push(t_stack *s, int val);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	dispatch(t_stack *a, t_stack *b, t_strategy strategy, int bench_mode);
void	sort_3(t_stack *a, t_stack *b);
int		is_valid_int(char *str);
long	ft_atol(const char *str);
int		has_duplicates(t_stack *a);
int		parse_args(int argc, char **argv, t_stack *a);
t_strategy	detect_strategy(int argc, char **argv, int *bench_mode);

#endif