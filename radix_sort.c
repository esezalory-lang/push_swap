/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:00:10 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/08 16:01:17 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_parser(t_stack *stack_a, t_stack *stack_b, int size, int args)
{
	int	iterations;

	virtualsort(stack_a, args);
	iterations = lindex_sinteger(stack_a);
	sorting_loop(stack_a, stack_b, iterations, size);
}

void	virtualsort(t_stack *stack_a, int args)
{
	int		min_value;
	int		index;
	t_list	*current;
	t_list	*lst_min_location;

	index = 0;
	while (index < args - 1)
	{
		current = stack_a->head;
		lst_min_location = NULL;
		while (current)
		{
			if ((lst_min_location == NULL || current->list_number < min_value)
				&& current->list_position == -1)
			{
				min_value = current->list_number;
				lst_min_location = current;
			}
			current = current->next;
		}
		if (lst_min_location == NULL)
			break ;
		lst_min_location->list_position = index;
		index++;
	}
}

int	lindex_sinteger(t_stack *stack_a)
{
	t_list	*current;
	int		largest_index;
	int		product;
	int		smallest_integer;

	current = stack_a->head;
	largest_index = current->list_position;
	while (current)
	{
		if (largest_index < current->list_position)
			largest_index = current->list_position;
		current = current->next;
	}
	product = 1;
	smallest_integer = 0;
	while (product <= (largest_index - 1))
	{
		product = 2 * product;
		smallest_integer++;
	}
	return (smallest_integer);
}

void	sorting_loop(t_stack *stack_a, t_stack *stack_b, int k, int size)
{
	int		i;
	int		j;
	t_list	*current;

	i = 0;
	while (i <= k - 1)
	{
		j = 0;
		while (j < size)
		{
			current = stack_a->head;
			if ((current->list_position >> i & 1) == 0)
				pb(stack_a, stack_b);
			else if ((current->list_position >> i & 1) == 1)
				ra(stack_a);
			j++;
		}
		while (stack_b->head != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}
