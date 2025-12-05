/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:08:14 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/04 12:43:05 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minisort_helper(t_stack *stack_a)
{
	int	min_pos;

	min_pos = ft_lstmin(stack_a->head);
	if (min_pos == 2)
		ra(stack_a);
	else if (min_pos == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_pos == 4)
		rra(stack_a);
}
