/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:17:54 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/08 15:51:04 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rrb(t_stack *stack_b)
{
	t_list	*old_head;
	t_list	*new_tail;

	old_head = stack_b->head;
	new_tail = stack_b->head;
	while (new_tail->next != stack_b->tail)
		new_tail = new_tail->next;
	stack_b->tail->next = old_head;
	stack_b->head = stack_b->tail;
	stack_b->tail = new_tail;
	new_tail->next = NULL;
	write(1, "rrb\n", 4);
}
