/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:07:18 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:19:17 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1.
//this is local copy (**lst is passed), can only change *lst by reference
//its unnecessary as the last node -> next is null and will be assigned at
//the last iteration of the while loop
	lst = NULL;

2.
// *lst -> next will be parses as *(lst -> next) which is not what we want
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

/*
#include <stdio.h>
void	print_nodes(t_list *node)
{
	int i;

	i = 0;
	while(node)
	{
		printf("Node %d's address: %p\n", i, node);
		printf("Node %d's data: %d\n", i, *(int *)node -> content);
		node = node -> next;
		i++;
	}
}

void	delcontent(void *content)
{
	free(content);
}

int	main(void)
{
	int		*a;
	int		*b;
	int		*c;

	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	
	head = NULL;
	a = malloc(sizeof(int));
	a[0] = 42;
	b = malloc(sizeof(int));
	b[0] = 43;
	c = malloc(sizeof(int));
	c[0] = 44;

	node1 = ft_lstnew(a); 
	if (!node1)
		return (0);
	node2 = ft_lstnew(b); 
	if (!node2)
		return (0);
	node3 = ft_lstnew(c); 
	if (!node3)
		return (0);	

	printf("------Creating list with 3 nodes------------\n");
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	print_nodes(head);

	ft_lstclear(&head, delcontent);
	if (!head)
		printf("list is deleted\n");
	else
		printf("Error\n");
}
*/
