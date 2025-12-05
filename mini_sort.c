/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:17:32 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/04 13:03:03 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_parser(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	if (!stack_a || !stack_a->head)
		return ;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	size = ft_lstsize(stack_a->head);
	if (size == 2)
	{
		if (stack_a->head->list_number > stack_a->tail->list_number)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}

void	sort_three(t_stack *stack_a)
{
	t_list	*first_node;
	t_list	*middle_node;
	t_list	*end_node;

	first_node = stack_a->head;
	middle_node = first_node->next;
	end_node = stack_a->tail;
	if (first_node->list_number > middle_node->list_number
		&& first_node->list_number > end_node->list_number)
		ra(stack_a);
	else if (middle_node->list_number > first_node->list_number
		&& middle_node->list_number > end_node->list_number)
		rra(stack_a);
	first_node = stack_a->head;
	middle_node = first_node->next;
	if (first_node->list_number > middle_node->list_number)
		sa(stack_a);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	minisort_helper(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
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
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (min_pos == 5)
		rra(stack_a);
	pb(stack_a, stack_b);
	minisort_helper(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
