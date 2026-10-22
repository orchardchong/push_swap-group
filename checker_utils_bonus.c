/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:29:12 by junlim            #+#    #+#             */
/*   Updated: 2026/10/22 19:29:12 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
same as pa/pb in push.c but without ft_printf, since checker must only
print OK/KO/Error. pa = push_silent(a, b), pb = push_silent(b, a)
*/
static void	push_silent(t_stack *dst, t_stack *src)
{
	t_node	*top;

	if (!dst || !src || src->size == 0)
		return ;
	src->size--;
	top = src->top;
	if (src->size == 0)
		src->top = NULL;
	else
	{
		src->top->prev->next = src->top->next;
		src->top->next->prev = src->top->prev;
		src->top = src->top->next;
	}
	ft_doubly_lstadd_front(dst, top);
}

/*
n = 4 compares the '\0' too, so "sa\n" matches but "sab\n" or "sa"
(last line without '\n') do not.
print flag 1 = silent, bench NULL = no counting.
*/
static int	apply_swap_push(t_stacks *s, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(s->a, 1, NULL);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(s->b, 1, NULL);
	else if (!ft_strncmp(line, "ss\n", 4))
	{
		sa(s->a, 1, NULL);
		sb(s->b, 1, NULL);
	}
	else if (!ft_strncmp(line, "pa\n", 4))
		push_silent(s->a, s->b);
	else if (!ft_strncmp(line, "pb\n", 4))
		push_silent(s->b, s->a);
	else
		return (0);
	return (1);
}

static int	apply_rotate(t_stacks *s, char *line)
{
	if (!ft_strncmp(line, "ra\n", 4))
		ra(s->a, 1, NULL);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(s->b, 1, NULL);
	else if (!ft_strncmp(line, "rr\n", 4))
	{
		ra(s->a, 1, NULL);
		rb(s->b, 1, NULL);
	}
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(s->a, 1, NULL);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(s->b, 1, NULL);
	else if (!ft_strncmp(line, "rrr\n", 5))
	{
		rra(s->a, 1, NULL);
		rrb(s->b, 1, NULL);
	}
	else
		return (0);
	return (1);
}

//returns 1 if line is a valid instruction (and applies it), 0 if not
int	apply_op(t_stacks *s, char *line)
{
	if (apply_swap_push(s, line))
		return (1);
	return (apply_rotate(s, line));
}
