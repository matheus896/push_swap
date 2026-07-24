/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfreitass <vfreitas@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:18:44 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/21 07:00:00 by vfreitass        ###   ########.fr       */
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
	int cap;
}	t_stack;

typedef	struct s_chunk
{
	int	min;
	int	max;
	int	width;
}	t_chunk;


typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

void		init(t_stack *s, int cap);
void		push(t_stack *s, int val);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		dispatch(t_stack *a, t_stack *b, t_strategy strategy,
				int bench_mode);
void		sort_3(t_stack *a, t_stack *b);
void		selection_sort(t_stack *a, t_stack *b);
int			is_valid_int(char *str);
long		ft_atol(const char *str);
int			has_duplicates(t_stack *a);
int			parse_args(int argc, char **argv, t_stack *a);
t_strategy	detect_strategy(int argc, char **argv, int *bench_mode);

int	ft_sqrt(int number);
void	init_chunk(t_chunk *chunk, int stack_size);
void	next_chunk(t_chunk *chunk, int stack_size);
void	cosort(t_stack *a, int *cpy);
int	is_chunk(int value, int *sorted, int size, t_chunk *chunk);
int chunk_count(t_chunk *chunk);
int	find_max_pos(t_stack *b);
void	move_max_to_top(t_stack *b);
void	restore_stack(t_stack *a, t_stack *b);
void	chunk_sort(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack, char *name);
size_t	*operation_counter(void);
void	print_op(char *op);
size_t	ft_strlen(const char *s);



#endif