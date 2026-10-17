/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 08:17:19 by junlim            #+#    #+#             */
/*   Updated: 2026/10/17 10:49:28 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// free!
// this should be used after input validation to make sure values within INT
// range
int	*get_int_arr(char **args, int size)
{
	int	*arr;
	int	i;

	i = 0;
	if (!args || size < 0)
		return (NULL);
	arr = ft_calloc(size, sizeof(int));
	if (!arr)
		return (NULL);
	while (args[i])
	{
		arr[i] = ft_atol(args[i]);
		i++;
	}
	return (arr);
}

//Example
/*
5 2 4 1 3 key = 2
5 5 4 1 3 swap
2 5 4 1 3 key = 4
2 5 5 1 3 swap
2 4 5 1 3 key = 1
2 4 5 5 3
2 4 4 5 3
2 2 4 5 3
1 2 4 5 3 key = 3
1 2 4 5 5
1 2 4 4 5
1 2 3 4 5
*/
/*
not using int **arr, as we only wants to modify the values,
not the address
*/
void	insertion_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	assign_sorted_index(t_stack *stack, int *sorted_array)
{
	t_node	*curr;
	int		i;
	int		j;

	i = 0;
	curr = stack->top;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (curr->num == sorted_array[j])
				curr->sorted_index = j;
			j++;
		}
		curr = curr->next;
		i++;
	}
}
