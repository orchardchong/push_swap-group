/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 06:41:09 by junlim            #+#    #+#             */
/*   Updated: 2026/10/19 08:37:04 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int n)
{
	int	i;

	i = 1;
	while (i <= n / i)
		i++;
	return (i - 1);
}

/* v1
	int	i;

	i = 1;
	if (n <= 0)
		return (0);
	while (i < n / i)
		i++;
	if (i != n / i)
		i--; 
*/
static int	find_max_doubly(t_stack *s)
{
	int		i;
	int		max;
	t_node	*curr;

	i = 0;
	max = 0;
	curr = s->top;
	while (i < s->size)
	{
		if (curr->sorted_index > max)
			max = curr -> sorted_index;
		curr = curr->next;
		i++;
	}
	return (max);
}

static int	find_node_pos(t_stack *s, int sorted_index)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = s->top;
	while (i < s->size)
	{
		if (curr->sorted_index == sorted_index)
			break ;
		curr = curr->next;
		i++;
	}
	return (i);
}

/*
1. pos <= b->size / 2 to avoid extra ops then pos b->size is odd
	example:
	if pos = 5, size = 11
		cost would be 11/2 = 5
	using < will go to else branch, costing 6 ops instead of 5
*/
static void	push_max_to_a(t_stack *a, t_stack *b)
{
	int	cost;
	int	pos;

	while (b->size)
	{
		pos = find_node_pos(b, find_max_doubly(b));
		if (pos <= b->size / 2)
		{
			cost = pos;
			while (cost--)
				rb(b, 0);
		}
		else
		{
			cost = b->size - pos;
			while (cost--)
				rrb(b, 0);
		}
		pa(a, b);
	}
}

/*
1. < chunk_start_i should be the first if, if not its not reachable as
chunk_start_i + chunk_size is always bigger.

*/
void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_start_i;
	int	chunk_size;

	chunk_start_i = 0;
	chunk_size = get_chunk_size(a->size);
	while (a->size)
	{
		if (a->top->sorted_index < chunk_start_i)
		{
			pb(a, b);
			rb(b, 0);
			chunk_start_i++;
		}
		else if (a->top->sorted_index < chunk_start_i + chunk_size)
		{
			pb(a, b);
			chunk_start_i++;
		}
		else
			ra(a, 0);
	}
	push_max_to_a(a, b);
}
