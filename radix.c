/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:03:34 by junlim            #+#    #+#             */
/*   Updated: 2026/10/19 07:25:34 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
has_other_group is needed to make sure the current stack is always on top
before next sort.

Example:
A (top first):  [1 0 1 0 | X Y]     group size 4, X Y = other group below
zeroes = 2

ra  → [0 1 0 X Y 1]
pb  → A [1 0 X Y 1]      B [0]
ra  → [0 X Y 1 1]
pb  → A [X Y 1 1]        B [0 0]    ← stop (all zeroes found)

no rra:   A [X Y 1 1]  → sort_a(…, 2) takes the top 2 = X Y   ✗ wrong group
rra ×2:   A [1 1 X Y]  → sort_a(…, 2) takes the top 2 = 1 1   ✓
*/
/*
1. After pb, a->size shrinks by zeroes after pb, so stacksize - zeroes
2. in stack a, if the bit_pos has 0s, pushed to b
*/
static int	split_a(t_stack *a, t_stack *b, int bit_pos, int stacksize)
{
	int	i;
	int	zeroes;
	int	rra_count;

	i = 0;
	rra_count = 0;
	zeroes = count_matching_bit(a, stacksize, bit_pos, 0);
	while (i < zeroes)
	{
		if ((a->top->sorted_index >> bit_pos & 1) == 0)
		{
			pb(a, b);
			i++;
		}
		else
		{
			ra(a, 0);
			rra_count++;
		}
	}
	if (stacksize - zeroes < a->size)
		while (rra_count--)
			rra(a, 0);
	return (zeroes);
}

static int	split_b(t_stack *a, t_stack *b, int bit_pos, int stacksize)
{
	int	i;
	int	ones;
	int	rrb_count;

	i = 0;
	rrb_count = 0;
	ones = count_matching_bit(b, stacksize, bit_pos, 1);
	while (i < ones)
	{
		if ((b->top->sorted_index >> bit_pos & 1) == 1)
		{
			pa(a, b);
			i++;
		}
		else
		{
			rb(b, 0);
			rrb_count++;
		}
	}
	if (stacksize - ones < b->size)
		while (rrb_count--)
			rrb(b, 0);
	return (ones);
}
static void	sort_b(t_stack *a, t_stack *b, int bit_pos, int stacksize);
/*
bit_post should be max_bit_count - 1 at start
*/

static void	sort_a(t_stack *a, t_stack *b, int bit_pos, int stacksize)
{
	int	zeroes;
	int	ones;

	if (stacksize == 0)
		return ;
	if (stacksize == 1)
	{
		pb(a, b);
		return ;
	}
	zeroes = split_a(a, b, bit_pos - 1, stacksize);
	ones = stacksize - zeroes;
	sort_b(a, b, bit_pos - 1, zeroes);
	sort_a(a, b, bit_pos - 1, ones);
}

static void	sort_b(t_stack *a, t_stack *b, int bit_pos, int stacksize)
{
	int	zeroes;
	int	ones;

	if (stacksize < 2)
		return ;
	ones = split_b(a, b, bit_pos - 1, stacksize);
	zeroes = stacksize - ones;
	sort_b(a, b, bit_pos - 1, zeroes);
	sort_a(a, b, bit_pos - 1, ones);
}

void	radix_sort(t_stack *a, t_stack *b, int max)
{
	sort_a(a, b, get_max_num_bits_count(max), a->size);
	while (b->size)
		pa(a, b);
}
