/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:50:54 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:17:08 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	if (last_node)
		last_node -> next = new;
	else
		last_node = new;
if last_node is null, which means the list is empty,
this will make lst start pointing to new node because last_node is local
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!new || !lst)
		return ;
	last_node = ft_lstlast(*lst);
	if (last_node)
		last_node -> next = new;
	else
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
	
	// node1 = NULL;
	node1 = ft_lstnew(&a); 
	if (!node1)
		return (0);
	printf("node1 addrs: %p\n", node1);
	printf("node1 content: %d\n", *(int *)node1 -> content);
	node2 = ft_lstnew(&b);
	if (!node2)
		return (0);
	printf("node2 addrs: %p\n", node2);
	printf("node2 content: %d\n", *(int *)node2 -> content);
	//add node 2 infront of node1
	printf("------Creating list by adding node2 at back of node1------------\n");

	ft_lstadd_back(&node1, node2);
	printf("first node addrs: %p\n", node1);
	printf("first node -> next: %p\n", node1 -> next);
	// printf("last node address: %p\n", ft_lstlast(node1));
	// printf("last node content: %d\n", *(int *)ft_lstlast(node1) -> content);
	free(node1 -> next); //if node1 is free first then go to the next node
	free(node1);
}
*/
