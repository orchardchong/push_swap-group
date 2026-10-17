/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:47:18 by ochong            #+#    #+#             */
/*   Updated: 2026/10/12 22:47:18 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min_node(t_stack *stack_a)
{
	t_node	*current;
	t_node	*min_node;

	if (stack_a == NULL || stack_a->top == NULL)
		return (NULL);
	min_node = stack_a->top;
	current = stack_a->top->next;
	while (current != stack_a->top)
	{
		if (current->num < min_node->num)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	simple(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;

	while (stack_a->size > 3)
	{
		min_node = get_min_node(stack_a);
		while (stack_a->top != min_node)
			ra(stack_a); 
		pb(stack_a, stack_b);
	}
	if (stack_a->size == 3)
		sorted_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

/*#include <stdio.h>
int	main(void)
{
	t_stack stack_a;
	t_stack stack_b;
	t_node *current;

	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(40));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(10));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(50));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(20));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(30));
	printf("BEFORE SORTING\n");
	current = stack_a.top;
	while (current->next != stack_a.top)
	{
		printf("%d ->",current->num);
		current = current->next;
	}
	printf("%d ->",current->num);
	printf("\n");
	printf("AFTER SORTING\n");
	simple(&stack_a,&stack_b);
	printf("\n");
	if (stack_a.top != NULL)
	{
		current = stack_a.top;
		while (current->next != stack_a.top)
		{
			printf("%d -> ", current->num);
			current = current->next;
		}
		printf("%d\n", current->num);
	}
	ft_clearstack(&stack_a);
	ft_clearstack(&stack_b);
	return (0);
}*/
