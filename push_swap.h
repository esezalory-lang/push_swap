/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:43:16 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/08 16:04:53 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Structs
typedef struct s_list	t_list;
typedef struct s_stack	t_stack;

// Main Functions
int						main(int argc, char **argv);
int						error_line_saver(int argc, char **argv);
int						create_list(t_stack *stack_a, char **argv);

// Error Handling Utils
int						error_parsing(int argc, char **argv);
int						valid_int(char **nptr);
int						check_dup(int args, int *array);
int						check_sorted(int args, int *array);

// Sorting Functions
void					mini_sort_parser(t_stack *stack_a, t_stack *stack_b);
void					sort_three(t_stack *stack_a);
void					sort_four(t_stack *stack_a, t_stack *stack_b);
void					sort_five(t_stack *stack_a, t_stack *stack_b);
void					radix_parser(t_stack *stack_a, t_stack *stack_b,
							int size, int args);
void					virtualsort(t_stack *stack_a, int args);
int						lindex_sinteger(t_stack *stack_a);
void					sorting_loop(t_stack *stack_a, t_stack *stack_b, int k,
							int size);

// Moves
void					pa(t_stack *stack_a, t_stack *stack_b);
void					ra(t_stack *stack_a);
void					rra(t_stack *stack_a);
void					sa(t_stack *stack_a);
void					pb(t_stack *stack_a, t_stack *stack_b);
void					rrb(t_stack *stack_b);

// Libft Functions
long					ft_atoi(const char *nptr);
void					bring_min_to_top(t_stack *stack_a);

// List Utils
void					ft_lstclear(t_list **lst);
int						ft_lstsize(t_list *stack);
t_list					*ft_lstnew(int list_value);
int						ft_lstmin(t_list *lst);

typedef struct s_list
{
	int					list_number;
	int					list_position;
	t_list				*next;
}						t_list;

typedef struct s_stack
{
	t_list				*head;
	t_list				*tail;
}						t_stack;

#endif
