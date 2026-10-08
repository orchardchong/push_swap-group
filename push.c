/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:34:00 by junlim            #+#    #+#             */
/*   Updated: 2026/10/08 16:32:36 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
stack_b->top->prev is last node
stack_b->top->next is second node

*stack_a and *stack_b could be null.
example for its initialization:
	t_stack *stack_a = NULL; OR
	t_stack stack_a;
*/
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b_top;

	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	stack_b->size--;
	b_top = stack_b->top;
	if (stack_b->size == 0)
		stack_b->top = NULL;
	else
	{
		stack_b->top->prev->next = stack_b->top->next;
		stack_b->top->next->prev = stack_b->top->prev;
		stack_b->top = stack_b->top->next;
	}
	ft_doubly_lstadd_front(stack_a, b_top);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_top;

	if (!stack_a || !stack_b || stack_a->size == 0)
		return ;
	stack_a->size--;
	a_top = stack_a->top;
	if (stack_a->size == 0)
		stack_a->top = NULL;
	else
	{
		stack_a->top->prev->next = stack_a->top->next;
		stack_a->top->next->prev = stack_a->top->prev;
		stack_a->top = stack_a->top->next;
	}
	ft_doubly_lstadd_front(stack_b, a_top);
}

// void	fill_arr(t_stack *stack, int *arr, int arrsize)
// {
// 	while (--arrsize > -1)
// 		ft_doubly_lstadd_front(stack, ft_doubly_lstnew(arr[arrsize]));
// }

// void	print_stack(t_stack stack, char* stack_name)
// {
// 	ft_printf("Stack %s :", stack_name);
// 	while (stack.size--)
// 	{
// 		ft_printf("%d ", stack.top->num);
// 		stack.top = stack.top->next;
// 	}
// 	if(!stack.top)
// 		ft_printf("empty");
// 	ft_printf("\n");
// }

/*
when stack a,b is not initialized, valgrind shows:
==121024== Conditional jump or move depends on uninitialised value(s),
at ft_doubly_lstadd_back, stack->size is used in if(...), which caused
errors
*/
// int	main(void)
// {
// 	t_stack a;
// 	t_stack b;
// 	int a_arr[] = {1,2,3};
// 	int b_arr[] = {4,5,6};

// 	a.top = NULL;
// 	a.size = 0;
// 	b.top = NULL;
// 	b.size = 0;
// 	ft_printf("-----------pa--------------\n");
// 	fill_arr(&a, a_arr, 3);
// 	fill_arr(&b, b_arr, 3);
// 	print_stack(a, "A");
// 	print_stack(b, "B");
// 	pa(&a, &b);
// 	print_stack(a, "A after pa");
// 	print_stack(b, "B after pa");
// 	pa(&a, &b);
// 	print_stack(a, "A after pa");
// 	print_stack(b, "B after pa");
// 	pa(&a, &b);
// 	print_stack(a, "A after pa");
// 	print_stack(b, "B after pa");
// 	ft_printf("-----------pa if B is empty--------------\n");
// 	pa(&a, &b);
// 	print_stack(a, "A after pa");
// 	print_stack(b, "B after pa");
// 	ft_printf("-----------pb--------------\n");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");
// 	ft_printf("-----------pb if A is empty--------------\n");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");
// 	pb(&a, &b);
// 	print_stack(a, "A after pb");
// 	print_stack(b, "B after pb");

// 	ft_printf("-----------pa--------------\n");
// 	pa(&a, &b);
// 	print_stack(a, "A after pa");
// 	print_stack(b, "B after pa");
// 	pa(&a, &b);
// 	print_stack(a, "A after pa");
// 	print_stack(b, "B after pa");	
// 	//check whether pointer allocation is correct for the first and last node
// 	ft_printf("-----------check circular link of A B--------------\n");
// 	ft_printf("A first node's prev %d\n", a.top->prev->num);
// 	ft_printf("A last node's next %d\n", a.top->prev->next->num);
// 	ft_printf("B first node's prev %d\n", b.top->prev->num);
// 	ft_printf("B last node's next %d\n", b.top->prev->next->num);
// 	ft_clearstack(&a);
// 	ft_clearstack(&b);
// }