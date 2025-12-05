/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:17:54 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/04 13:02:55 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*moving_node;
	t_list	*next_node;

	if (!stack_b || !stack_b->head)
		return ;
	moving_node = stack_b->head;
	next_node = moving_node->next;
	stack_b->head = next_node;
	if (!stack_b->head)
		stack_b->tail = next_node;
	moving_node->next = stack_a->head;
	if (!moving_node->next)
		stack_a->tail = moving_node;
	stack_a->head = moving_node;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*moving_node;
	t_list	*next_node;

	if (!stack_a || !stack_a->head)
		return ;
	moving_node = stack_a->head;
	next_node = moving_node->next;
	stack_a->head = next_node;
	if (!stack_a->head)
		stack_a->tail = next_node;
	moving_node->next = stack_b->head;
	if (!moving_node->next)
		stack_b->tail = moving_node;
	stack_b->head = moving_node;
	write(1, "pb\n", 3);
}

void	ra(t_stack *stack_a)
{
	t_list	*moving_node;

	moving_node = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_a->tail->next = moving_node;
	stack_a->tail = moving_node;
	moving_node->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack *stack_a)
{
	t_list	*old_head;
	t_list	*new_tail;

	old_head = stack_a->head;
	new_tail = stack_a->head;
	while (new_tail->next != stack_a->tail)
		new_tail = new_tail->next;
	stack_a->tail->next = old_head;
	stack_a->head = stack_a->tail;
	stack_a->tail = new_tail;
	new_tail->next = NULL;
	write(1, "rra\n", 4);
}

void	sa(t_stack *stack_a)
{
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;

	first_node = stack_a->head;
	second_node = first_node->next;
	third_node = second_node->next;
	if (second_node->next == NULL)
		stack_a->tail = first_node;
	stack_a->head = second_node;
	first_node->next = third_node;
	second_node->next = first_node;
	write(1, "sa\n", 4);
}
