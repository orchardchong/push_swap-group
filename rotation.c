/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 20:25:01 by junlim            #+#    #+#             */
/*   Updated: 2026/10/08 17:12:11 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> next;
}

void	rb(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack -> top = stack -> top -> next;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

// Share with reverse_rotation.c
void	print_each_node_num(char *str, t_stack stack)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = stack.top;
	ft_printf(str);
	while (i++ < stack.size)
	{
		ft_printf("%d ", cur->num);
		cur = cur->next;
	}
}

// int	main(void)
// {
// 	t_stack a;
// 	t_stack b;
// 	t_stack c;

// 	a.top = NULL;
// 	a.size = 0;
// 	b.top = NULL;
// 	b.size = 0;
// 	c.top = NULL;
// 	c.size = 0;

// 	ft_doubly_lstadd_back(&a, ft_doubly_lstnew(1));
// 	ft_doubly_lstadd_back(&a, ft_doubly_lstnew(2));
// 	ft_doubly_lstadd_back(&a, ft_doubly_lstnew(3));

// 	ft_doubly_lstadd_back(&b, ft_doubly_lstnew(4));
// 	ft_doubly_lstadd_back(&b, ft_doubly_lstnew(5));
// 	ft_doubly_lstadd_back(&b, ft_doubly_lstnew(6));

// 	ft_doubly_lstadd_back(&c, ft_doubly_lstnew(7));

// 	print_each_node_num("stack a init: ", a);
// 	print_each_node_num("\nstack b init: ", b);
// 	print_each_node_num("\nstack c init: ", c);
// 	ft_printf("\n--------------------------------");
// 	rr(&a, &b);
// 	print_each_node_num("\nStack a fter rr: ", a);
// 	print_each_node_num("\nStack b fter rr: ", b);
// 	ft_printf("\n--------------------------------");

// 	rrr(&a, &b);
// 	print_each_node_num("\nStack a fter rrr: ", a);
// 	print_each_node_num("\nStack b fter rrr: ", b);
// 	ft_printf("\n--------------------------------");

// 	rr(&a, &c);
// 	print_each_node_num("\nStack a fter rr: ", a);
// 	print_each_node_num("\nStack c fter rr: ", c);
// 	ft_printf("\n--------------------------------");

// }