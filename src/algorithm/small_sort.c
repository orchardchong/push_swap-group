/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 00:00:00 by junlim            #+#    #+#             */
/*   Updated: 2026/10/26 00:00:00 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//how many steps from the top to reach target
static int	get_position(t_stack *stack, t_node *target)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->top;
	while (current != target)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

//bring the min to the top by the shorter direction, then push it to b
static void	push_min_to_b(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	t_node	*min_node;

	min_node = get_min_node(stack_a);
	if (get_position(stack_a, min_node) <= stack_a->size / 2)
	{
		while (stack_a->top != min_node)
			ra(stack_a, 0, bench);
	}
	else
	{
		while (stack_a->top != min_node)
			rra(stack_a, 0, bench);
	}
	pb(stack_a, stack_b, bench);
}

//only called when stack_a is unsorted, so 2 numbers always need sa
//4 or 5 numbers: push the smallest ones to b, sort 3, push them back
void	small_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (stack_a->size == 2)
		sa(stack_a, 0, bench);
	else if (stack_a->size == 3)
		sorted_three(stack_a, bench);
	else
	{
		while (stack_a->size > 3)
			push_min_to_b(stack_a, stack_b, bench);
		sorted_three(stack_a, bench);
		while (stack_b->size > 0)
			pa(stack_a, stack_b, bench);
	}
}
