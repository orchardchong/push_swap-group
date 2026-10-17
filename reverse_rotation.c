/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 08:53:38 by junlim            #+#    #+#             */
/*   Updated: 2026/10/17 08:36:47 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int print_both)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> prev;
	if (!print_both)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack, int print_both)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> prev;
	if (!print_both)
		ft_printf("rrb\n");

}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	ft_printf("rrr\n");
}
