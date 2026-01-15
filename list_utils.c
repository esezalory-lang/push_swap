/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:30:06 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/08 14:59:05 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*new_node;

	if (!*lst)
		return ;
	current = *lst;
	while (current)
	{
		new_node = current->next;
		free(current);
		current = new_node;
	}
	*lst = NULL;
}

t_list	*ft_lstnew(int list_value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new_node)
		return (0);
	new_node->list_number = list_value;
	new_node->list_position = -1;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list *stack)
{
	int		size;
	t_list	*current;

	if (stack == NULL)
		return (0);
	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	ft_lstmin(t_list *lst)
{
	int		min_val;
	int		min_index;
	t_list	*current;
	int		i;

	if (!lst)
		return (0);
	current = lst;
	min_val = current->list_number;
	min_index = 1;
	i = 1;
	current = current->next;
	i++;
	while (current)
	{
		if (current->list_number < min_val)
		{
			min_val = current->list_number;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}
