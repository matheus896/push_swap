/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheusms1 <matheusms1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:46:40 by matheusms1        #+#    #+#             */
/*   Updated: 2026/07/21 17:02:12 by matheusms1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	has_duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->arr[i] == a->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill_stack(int argc, char **argv, t_stack *a)
{
	int		i;
	long	val;

	i = argc - 1;
	while (i >= 1)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			i--;
		else
		{
			val = ft_atol(argv[i]);
			if (!is_valid_int(argv[i]) || val < INT_MIN || val > INT_MAX)
			{
				free(a->arr);
				return (0);
			}
			push(a, (int)val);
			i--;
		}
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	init(a, count);
	if (!fill_stack(argc, argv, a))
		return (0);
	if (has_duplicates(a))
	{
		free(a->arr);
		return (0);
	}
	return (1);
}
