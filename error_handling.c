/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:42:44 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/08 16:58:07 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_parsing(int argc, char **argv)
{
	int	i;
	int	*error_array;

	i = 1;
	error_array = malloc(sizeof(int) * argc);
	if (!error_array)
		return (0);
	if (valid_int(argv) == 0)
		return (free(error_array), 0);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (0);
		error_array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (check_dup(argc, error_array) == 0)
		return (free(error_array), 0);
	if (check_sorted(argc, error_array) == 0)
		return (free(error_array), 2);
	return (free(error_array), 1);
}

int	valid_int(char **nptr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (nptr[i])
	{
		j = 0;
		if (nptr[i][0] == '\0')
			return (0);
		if (nptr[i][j] == '-' || nptr[i][j] == '+')
		{
			j++;
			if (!nptr[i][j])
				return (0);
		}
		while (nptr[i][j])
		{
			if (!(nptr[i][j] >= '0' && nptr[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dup(int args, int *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < args - 1)
	{
		j = i + 1;
		while (j < args - 1)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sorted(int args, int *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < args - 1)
	{
		j = i + 1;
		while (j < args - 1)
		{
			if (array[i] > array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
