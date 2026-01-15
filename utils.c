/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:50:22 by esezalor          #+#    #+#             */
/*   Updated: 2026/01/15 16:37:08 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	new_nbr;

	i = 0;
	sign = 1;
	new_nbr = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		new_nbr = (new_nbr * 10) + (nptr[i] - 48);
		i++;
	}
	return (new_nbr * sign);
}

void	bring_min_to_top(t_stack *stack_a)
{
	int	size;
	int	min_pos;

	size = ft_lstsize(stack_a->head);
	min_pos = ft_lstmin(stack_a->head);
	if (min_pos <= (size / 2) + 1)
	{
		while (min_pos > 1)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos <= size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
}
