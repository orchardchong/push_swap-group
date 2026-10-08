/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 08:23:59 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:16:44 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	int	a = 42;
	int b = 101;
	t_list	*node1;
	t_list	*node2;
	
	node1 = ft_lstnew(&a);
	if (!node1)
		return (0);
	printf("node1's address: %p\n", node1);
	printf("node1's content: %d\n", *(int *)node1 -> content);
	printf("node1's next address: %p\n", node1 -> next);
	printf("---------------------------------------------------\n");
	node2 = ft_lstnew(&b);
	if (!node2)
		return (0);
	printf("node2's address: %p\n", node2);
	printf("node2's content: %d\n", *(int *)node2 -> content);
	printf("node2's next address: %p\n", node2 -> next);
	printf("---------------------------------------------------\n");	
	//add node 2 infront of node1
	ft_lstadd_front(&node1, node2);
	printf("After adding node2 infront of node1\n");
	printf("node1's address: %p\n", node1);
	printf("node1's content: %d\n", *(int *)node1 -> content);
	printf("node1's next address (node1 -> next): %p\n", node1 -> next);
	printf("---------------------------------------------------\n");	
	printf("node1 -> next -> content: %d\n", *(int *)node1 -> next -> content);
	printf("node1 -> next -> next : %p\n", node1 -> next -> next);
	printf("---------------------------------------------------\n");	
	printf("node2's address: %p\n", node2);
	printf("node2's content: %d\n", *(int *)node2 -> content);
	printf("node2's next address: %p\n", node2 -> next);
	free(node1->next); //if node1 is free first there cannot get to the next node
	free(node1);
}
*/
/*
1.
	printf("node1's address: %p\n", &node1);
	printf("head's next: %p\n", head->next);
shouldn't do &node1, this is the address of *node1, not node1 itself

2. can write as:
t_list *ft_lstadd_frount(t_list *head, t_list *new), but has to return t_list 
so that the changed *head can be tracked.
*head pointer is copy by value to this functino, if want to change *head
 pointer's value, need to pass **head

 Simple example:
 void	func(int **p) //or *p for testing
{
	int b = 1;
	*p = &b;
}

*/