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

# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_chunk
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
void		chunk_sort(t_stack *a, t_stack *b);
int			ft_sqrt(int n);
void		init_chunk(t_chunk *ck, int size);
void		next_chunk(t_chunk *ck, int size);
int			chunk_count(t_chunk *ck);
void		cosort(t_stack *a, int *cpy);
int			is_valid_int(char *str);
long		ft_atol(const char *str);
int			has_duplicates(t_stack *a);
int			parse_args(int argc, char **argv, t_stack *a);
t_strategy	detect_strategy(int argc, char **argv, int *bench_mode);
int			compute_disorder(t_stack *a);
void		print_bench(t_strategy s, int d);
void		bench_count(int op);

# define OP_SA  0
# define OP_SB  1
# define OP_SS  2
# define OP_PA  3
# define OP_PB  4
# define OP_RA  5
# define OP_RB  6
# define OP_RR  7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

#endif