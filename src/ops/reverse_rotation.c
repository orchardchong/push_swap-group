/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 08:53:38 by junlim            #+#    #+#             */
/*   Updated: 2026/10/21 20:36:25 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int print_rrr, t_bench *bench)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> prev;
	if (!print_rrr)
	{
		if (bench != NULL && bench->active == 1)
		{
			bench->rra++;
			bench->total_ops++;
		}
		ft_printf("rra\n");
	}
}

void	rrb(t_stack *stack, int print_rrr, t_bench *bench)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> prev;
	if (!print_rrr)
	{
		if (bench != NULL && bench->active == 1)
		{
			bench->rrb++;
			bench->total_ops++;
		}
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	rra(stack_a, 1, bench);
	rrb(stack_b, 1, bench);
	if (bench != NULL && bench->active == 1)
	{
		bench->rrr++;
		bench->total_ops++;
	}
	ft_printf("rrr\n");
}
