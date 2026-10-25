/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 17:47:24 by junlim            #+#    #+#             */
/*   Updated: 2026/10/08 16:34:47 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_doubly_lstnew(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new -> num = data;
	new -> sorted_index = -1;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

// last_node = stack -> top -> prev;
void	ft_doubly_lstadd_back(t_stack *stack, t_node *new)
{
	if (!new || !stack)
		return ;
	if (stack->size == 0)
	{
		stack -> top = new;
		stack -> top -> next = new;
		stack -> top -> prev = new;
	}
	else
	{
		stack -> top -> prev -> next = new;
		new -> prev = stack -> top -> prev;
		new -> next = stack -> top;
		stack -> top -> prev = new;
	}
	stack -> size++;
}

// Since no traverse is needed, can just add it to the back,
// reasign stack->to
void	ft_doubly_lstadd_front(t_stack *stack, t_node *new)
{
	ft_doubly_lstadd_back(stack, new);
	stack->top = new;
}

// void	ft_doubly_lstadd_front(t_stack *stack, t_node *new)
// {
// 	t_node	*last;

// 	last = NULL;
// 	if (stack == NULL || new == NULL)
// 		return ;
// 	if (stack->size == 0)
// 	{
// 		stack->top = new;
// 		stack->top->next = new;
// 		stack->top->prev = new;
// 	}
// 	else
// 	{
// 		last = stack->top->prev;
// 		new->next = stack->top;
// 		new->prev = last;
// 		stack->top->prev = new;
// 		last->next = new;
// 		stack->top = new;
// 	}
// 	stack -> size++;
// }
/*
stack->top = NULL; is need to avoid dangling, since temp also becomes
the last node when size == 1

when 1 node if left in a circular doubly linkedlst, below 3 is equal:
		stack -> top = new
		stack -> top -> next
		stack -> top -> prev

since the node that temp is poiniting if freed, and temp doesn't survive
after ft_clearstack, no memory leak.	
*/
void	ft_clearstack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (stack->size)
	{
		temp = stack->top->next;
		free(stack -> top);
		stack->top = temp;
		stack->size--;
	}
	stack->top = NULL;
}

// int	main(void)
// {
// 	t_stack	a;
// 	t_node	*cur;
// 	int		i;

// 	a.top = NULL;
// 	a.size = 0;
// 	ft_doubly_lstadd_back(&a, ft_doubly_lstnew(3));
// 	ft_doubly_lstadd_back(&a, ft_doubly_lstnew(2));
// 	ft_doubly_lstadd_back(&a, ft_doubly_lstnew(1));
// 	ft_printf("size = %d (expect 3)\n", a.size);
// 	cur = a.top;
// 	i = 0;
// 	ft_printf("forward:  ");
// 	while (i++ < a.size)
// 	{
// 		ft_printf("num:%d index: %d ", cur->num, cur->sorted_index);
// 		ft_printf(" | ");
// 		cur = cur->next;
// 	}
// 	cur = a.top->prev;
// 	i = 0;
// 	ft_printf("\nbackward: ");
// 	while (i++ < a.size)
// 	{
// 		ft_printf("num:%d index: %d ", cur->num, cur->sorted_index);
// 		ft_printf(" | ");
// 		cur = cur->prev;
// 	}
// 	ft_printf("\nfirst node prev: %d", a.top->prev->num);
// 	ft_printf("\nlast node next: %d", a.top->prev->next->num);
// 	ft_clearstack(&a);
// 	ft_printf("\nafter clear: size = %d, top = %p\n", a.size, (void *)a.top);
// 	return (0);
// }