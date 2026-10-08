/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 09:25:46 by junlim            #+#    #+#             */
/*   Updated: 2026/10/08 17:13:10 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swapping the contents of nodes have similar effect as changing their pointers
AWARE: make sure not pointer is pointing to any of the first 2 nodes, else
might have unexpected behaviour as the tracked node will have changed values.
*/
void	sa(t_stack *stack)
{
	int	num;
	int	sorted_index;

	if (!stack || stack->size < 2)
		return ;
	num = stack->top->num;
	sorted_index = stack->top->sorted_index;
	stack->top->num = stack->top->next->num;
	stack->top->sorted_index = stack->top->next->sorted_index;
	stack->top->next->num = num;
	stack->top->next->sorted_index = sorted_index;
}

void	sb(t_stack *stack)
{
	int	num;
	int	sorted_index;

	if (!stack || stack->size < 2)
		return ;
	num = stack->top->num;
	sorted_index = stack->top->sorted_index;
	stack->top->num = stack->top->next->num;
	stack->top->sorted_index = stack->top->next->sorted_index;
	stack->top->next->num = num;
	stack->top->next->sorted_index = sorted_index;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

// #include <stdio.h>
// static void	print_stack(const char *name, t_stack *s)
// {
// 	t_node	*n;
// 	int		i;
// 	printf("%s (size %d): ", name, s->size);
// 	if (!s->top)
// 	{
// 		printf("(empty)\n");
// 		return ;
// 	}
// 	n = s->top;
// 	i = 0;
// 	while (i < s->size)
// 	{
// 		printf("%d(i%d) ", n->num, n->sorted_index);
// 		n = n->next;
// 		i++;
// 	}
// 	printf("\n");
// }
// /* index is set to value * 10 so you can see num and index swap together */
// static void	fill(t_stack *s, int *arr, int count)
// {
// 	t_node	*node;
// 	int		i;

// 	s->top = NULL;
// 	s->size = 0;
// 	i = 0;
// 	while (i < count)
// 	{
// 		node = ft_doubly_lstnew(arr[i]);
// 		node->sorted_index = arr[i] * 10;
// 		ft_doubly_lstadd_back(s, node);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	t_stack	a;
// 	t_stack	b;
// 	int		arr_a[] = {1, 2, 3};
// 	int		arr_b[] = {4, 5, 6};
// 	int		one[] = {7};
// 	printf("--- sa on 1 2 3 (expect 2 1 3) ---\n");
// 	fill(&a, arr_a, 3);
// 	print_stack("A before", &a);
// 	sa(&a);
// 	print_stack("A after ", &a);
// 	ft_clearstack(&a);

// 	printf("\n--- sb on 4 5 6 (expect 5 4 6) ---\n");
// 	fill(&b, arr_b, 3);
// 	print_stack("B before", &b);
// 	sb(&b);
// 	print_stack("B after ", &b);
// 	ft_clearstack(&b);

// 	printf("\n--- ss: A 1 2 3 and B 4 5 6 (expect 2 1 3 / 5 4 6) ---\n");
// 	fill(&a, arr_a, 3);
// 	fill(&b, arr_b, 3);
// 	ss(&a, &b);
// 	print_stack("A after ", &a);
// 	print_stack("B after ", &b);
// 	ft_clearstack(&a);
// 	ft_clearstack(&b);

// 	printf("\n--- ss when B is too small (expect A swaps, B unchanged) ---\n");
// 	fill(&a, arr_a, 3);
// 	fill(&b, one, 1);
// 	ss(&a, &b);
// 	print_stack("A after ", &a);
// 	print_stack("B after ", &b);
// 	ft_clearstack(&a);
// 	ft_clearstack(&b);

// 	printf("\n--- sa on empty stack and NULL (expect no crash) ---\n");
// 	fill(&a, arr_a, 0);
// 	sa(&a);
// 	print_stack("A after ", &a);
// 	sa(NULL);
// 	printf("sa(NULL) ok\n");
// 	ft_clearstack(&a);
// 	return (0);
// }
