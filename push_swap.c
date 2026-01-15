/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:57:55 by esezalor          #+#    #+#             */
/*   Updated: 2026/01/15 16:32:27 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		list_size;

	if (error_line_saver(argc, argv) == -1)
		return (write(2, "Error\n", 6), -1);
	if (error_line_saver(argc, argv) == 0)
		return (0);
	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_b.head = NULL;
	stack_b.tail = NULL;
	if (argc > 2)
	{
		if (create_list(&stack_a, argv) == 0)
			return (write(2, "Error: Allocation Failure\n", 27), -1);
	}
	list_size = ft_lstsize(stack_a.head);
	if (list_size <= 5)
		mini_sort_parser(&stack_a, &stack_b);
	else
		radix_parser(&stack_a, &stack_b, list_size, argc);
	return (ft_lstclear(&stack_a.head), ft_lstclear(&stack_b.head), 0);
}

int	error_line_saver(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	if (error_parsing(argc, argv) == 0)
		return (-1);
	if (error_parsing(argc, argv) == 2)
		return (0);
	return (1);
}

int	create_list(t_stack *stack_a, char **argv)
{
	int		i;
	t_list	*new_node;

	i = 1;
	while (argv[i])
	{
		if (argv[i] == NULL)
			return (0);
		new_node = ft_lstnew(ft_atoi(argv[i]));
		if (!new_node)
			return (ft_lstclear(&stack_a->head), 0);
		if (stack_a->head == NULL)
		{
			stack_a->head = new_node;
			stack_a->tail = new_node;
		}
		else
		{
			stack_a->tail->next = new_node;
			stack_a->tail = new_node;
			new_node->next = NULL;
		}
		i++;
	}
	return (1);
}
