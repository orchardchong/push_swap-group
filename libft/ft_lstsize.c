/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:53:10 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:16:27 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	size = 0;
	while (lst)
	{
		lst = lst -> next;
		size++;
	}
	return (size);
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
	node2 = ft_lstnew(&b);
	if (!node2)
		return (0);
	//add node 2 infront of node1
	ft_lstadd_front(&node1, node2);
	printf("node1 addrs: %p\n", node1);
	printf("node1 -> next: %p\n", node1 -> next);
	printf("list size: %u\n", ft_lstsize(node1));
	free(node1->next); //if node1 is free first there cannot get to the next node
	free(node1);
}
*/