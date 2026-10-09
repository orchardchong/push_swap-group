/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metrics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 19:11:56 by ochong            #+#    #+#             */
/*   Updated: 2026/10/04 19:11:56 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_metrics(t_stack *stack_a)
{
	t_node	*current;
	t_node	*nextdigit;
	float	mistakes;
	float	total_pairs;

	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == stack_a->top)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;

	current = stack_a->top;
	while (current->next != stack_a->top)
	{
		nextdigit = current->next;
		while (nextdigit != stack_a->top)
		{
			total_pairs++;
			if (current->num > nextdigit->num)
				mistakes++;
			nextdigit = nextdigit->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}

/*#include <stdio.h>
int	main(void)
{
	t_stack	stack_a;
	t_node	node1;
	t_node	node2;
	t_node	node3;
	t_node	node4;
	float	score;

	node1.num = 4;
	node2.num = 2;
	node3.num = 3;
	node4.num = 1;
	node1.next = &node2;
	node1.prev = &node4;
	node2.next = &node3;
	node2.prev = &node1;
	node3.next = &node4;
	node3.prev = &node2;
	node4.next = &node1;
	node4.prev = &node3;
	stack_a.top = &node1;
	stack_a.size = 4;
	score = disorder_metrics(&stack_a);
	printf("Stack: [4, 2, 3, 1]\n");
	printf("Calculated Disorder Metric: %f\n", score);
	return (0);
}*/
