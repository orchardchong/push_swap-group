/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 21:35:27 by ochong            #+#    #+#             */
/*   Updated: 2026/10/11 21:35:27 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)// to check is it already sorted? 1 2 3
{
	t_node	*current;

	//if the stack is empty or has only 1 number, it's already sorted
	if (stack_a == NULL || stack_a->top == NULL || stack_a->size == 1)
		return (1);
	current = stack_a->top;
	while (current->next != stack_a->top)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	sorted_three(t_stack *stack_a) //do i need this?
{
	int	top;
	int	mid;
	int	bottom;

	top = stack_a->top->num;
	mid = stack_a->top->next->num;
	bottom = stack_a->top->prev->num;
	if (top > mid && top > bottom) //312
		ra(stack_a);
	if (mid > top && mid > bottom) //231
		rra(stack_a);
	top = stack_a->top->num;
	mid = stack_a->top->next->num;
	if (top > mid) //213
		sa(stack_a);
	return (0);
}

/*int main(void)
{
	t_stack stack_a;

	stack_a.top = NULL;
	stack_a.size = 0;
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(10));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(20));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(30));

	printf("Testing Sorted List (10 -> 20 -> 30):\n");
	if (is_sorted(&stack_a) == 1)
		printf("RESULT: Success! It knows it is sorted.\n\n");
	else
		printf("RESULT: Fail! It thinks it is unsorted.\n\n");
	ft_clearstack(&stack_a);
	return (0);
}*/

/*#include <stdio.h>
int	main(void)
{
	t_stack stack_a;
	t_node *current;
	
	stack_a.top = NULL;
	stack_a.size = 0;
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(3));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(2));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(1));
	printf("Before sorting \n");

	current = stack_a.top;
	while (current->next != stack_a.top)
	{
		printf("%d ->",current->num);
		current = current->next;
	}
	printf("%d ->\n",current->num);

	printf("After sorted 3 numbers\n");
	sorted_three(&stack_a);
	
	current = stack_a.top;
	while (current->next != stack_a.top)
	{
		printf("%d ->",current->num);
		current = current->next;
	}
	printf("%d ->\n",current->num);
	ft_clearstack(&stack_a);
	return (0);
}*/
