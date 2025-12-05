/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:57:55 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/04 14:01:28 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.c"
#include "libft_utils.c"
#include "list_utils.c"
#include "mini_sort.c"
#include "moves.c"
#include "push_swap.h"
#include "sort_utils.c"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc <= 1)
		return (write(2, "Error: Not Enough Arguments\n", 29), -1);
	if (argc == 2)
		return (0);
	if (error_parsing(argc, argv) == 0)
		return (write(2, "Error: Invalid List\n", 21), -1);
	stack_a.head = NULL;
	stack_a.tail = NULL;
	if (argc > 2)
	{
		if (create_list(&stack_a, argv) == 0)
			return (write(2, "Error: Allocation Failure\n", 27), -1);
	}
	if (ft_lstsize(stack_a.head) <= 5)
		mini_sort_parser(&stack_a, &stack_b);
	else
		virtualsort(&stack_a, argc);
	// 	radix_parser(&stack_a, &stack_b);
	debug_print_list(stack_a);
	return (0);
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

#include <stdio.h>

void	debug_print_list(t_stack stack)
{
	t_list	*current;

	current = stack.head;
	printf("\n====== STACK VISUALIZATION ======\n");
	printf("Stack Metadata:\n");
	printf("  HEAD: %p\n", (void *)stack.head);
	printf("  TAIL: %p\n", (void *)stack.tail);
	printf("---------------------------------\n");
	if (!current)
		printf("  [ Stack is EMPTY ]\n");
	while (current)
	{
		printf("Node [%p]\n", (void *)current);
		printf("  | Value (list_number):   %d\n", current->list_number);
		// Assuming list_position is initialized. If not, this might print garbage.
		printf("  | Rank  (list_position): %d\n",
			current->list_position);
		printf("  | Next:                  %p\n", (void *)current->next);
		printf("  -----------------------\n");
		current = current->next;
	}
	printf("====== END OF STACK ======\n\n");
}
