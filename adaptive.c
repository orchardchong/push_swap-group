/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 19:21:32 by ochong            #+#    #+#             */
/*   Updated: 2026/10/17 19:21:32 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	float	disorder;

	disorder = disorder_metrics(stack_a);
	if (disorder < 0.2)
		selection(stack_a, stack_b);
	else if (disorder >= 0.2 && disorder < 0.5)
		medium(stack_a, stack_b);
	else if (disorder >= 0.5)
		radix_sort(stack_a, stack_b);
}