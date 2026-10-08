/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:48:07 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:18:26 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1.
Since void *content of a node can points to data type, including
heap's addresses. So this function can correctly free those

2.
if (lst && del) using this coudnt free the nodes, separating them
allows at least the node to be free

3.!!! use valgrind to check memory leak whenever there is malloc/free
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst -> content);
	free(lst);
}

/*
#include <stdio.h>

void	delcontent(void *content)
{
	free(content);
}


// if a is malloc'ed, ft_lstnew(&a) means passing **a to content, which
// is pointing to *a, not the allocated memory.

// ft_lstadd_back(&node1, node1);
// this causes self referencing, whenever a function that needs to iterate
// nodes, it will stuck in a loop since the its always pointing to itself.
// so treate *node1 is null, and add node2 to it when using ft_lstadd_back()

int	main(void)
{
	int		*a;
	t_list	*node1;
	t_list	*node2;

	node1 = NULL;
	a = malloc(sizeof(int));
	a[0] = 42;
	node2 = ft_lstnew(a); 
	if (!node2)
		return (0);
	printf("node2 addrs: %p\n", node2);
	printf("node2 content: %d\n", *(int *)node2 -> content);

	printf("------Creating list by adding node2 only------------\n");
	ft_lstadd_back(&node1, node2);
	printf("first node addrs: %p\n", node1);
	printf("first node -> next: %p\n", node1 -> next);
	ft_lstdelone(node1, delcontent);
}
*/