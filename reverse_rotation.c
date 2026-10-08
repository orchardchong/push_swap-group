/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 08:53:38 by junlim            #+#    #+#             */
/*   Updated: 2026/10/07 08:53:51 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> prev;
}

void	rrb(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> prev;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
