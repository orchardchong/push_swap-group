/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:11:23 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:17:39 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*if *lst is null then return NULL already*/
t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a = 42;
	int b = 101;
	t_list	*node1;
	t_list	*node2;
	
	printf("----------------Creating 2 nodes-------------------------------\n");
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
	printf("------Creating list by adding node2 infront of node1------------\n");
	ft_lstadd_front(&node1, node2);
	printf("node1 addrs: %p\n", node1);
	printf("node1 -> next: %p\n", node1 -> next);
	printf("last node address: %p\n", ft_lstlast(node1));
	printf("last node content: %d\n", *(int *)ft_lstlast(node1) -> content);
	free(node1->next); //if node1 is free first there cannot get to the next node
	free(node1);
}
*/