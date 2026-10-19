/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 08:17:19 by junlim            #+#    #+#             */
/*   Updated: 2026/10/19 08:36:43 by junlim           ###   ########.fr       */
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

/*
can use max /= 2 also. In this case, shift every bits until
max becomes 0.

handles +ve values only because sorted_indexes have no -ve
*/
int	get_max_num_bits_count(int max)
{
	int	count;

	count = 0;
	while (max)
	{
		count++;
		max >>= 1;
	}
	return (count);
}

/*
Count how many 0s or 1s at the specific bit location. To stop early
when all the 0s or 1s are found, saving ops count and some processing power.

Bit loocation:
pos 0 1 2
----------
	0 0 1
	0 0 0
	0 1 0
at pos 0, 3 0s
at pos 1, 2 0s 1 1s

Saving ops count for [1 0 1 1]:
WITH count (zeros = 1)         WITHOUT count (loop all 4)
ra   (1 → bottom)              ra
pb   (0 pushed, STOP)          pb
rra  (undo 1 rotation)         ra   ← wasted
                               ra   ← wasted
                      		   rra ×3 (undo all 3 rotations)
= 3 ops                        = 7 ops
*/
int	count_matching_bit(t_stack *stack, int stacksize, int bit_pos, int bit)
{
	t_node	*curr;
	int		count;

	count = 0;
	curr = stack->top;
	while (stacksize--)
	{
		if ((curr->sorted_index >> bit_pos & 1) == bit)
			count++;
		curr = curr->next;
	}
	return (count);
}
