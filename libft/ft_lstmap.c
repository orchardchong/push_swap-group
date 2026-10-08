/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:04:07 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:18:53 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
1.
node = ft_lstnew(f(lst -> content))
	if (!node)
		{
			ft_lstdelone(node, del);
			return NULL;
		}
this does nothing as node is already null, should clear 
the new linkedlist instead

2.
if (!f)
		return (lst);
this returning the same pointer, which might cause double free() 
when expecting a new list to be returned

3. node = ft_lstnew(f(lst -> content));
void *f(lst -> content) might fails too, needs to be free ft_lstnew() fails
Store the return *content with a variable, so that it could be free
when node allocation fails
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*node;
	void	*new_content;

	new_head = NULL;
	node = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		new_content = f(lst -> content);
		node = ft_lstnew(new_content);
		if (!node)
		{
			if (del)
				del(new_content);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, node);
		lst = lst -> next;
	}
	return (new_head);
}
/*
#include <stdio.h>

void	print_nodes(t_list *node)
{
	int i;

	i = 0;
	while (node)
	{
		printf("Node %d's address: %p\n", i, node);
		printf("Node %d's data: %d\n", i, *(int *)node -> content);
		node = node -> next;
		i++;
	}
}

void	*add_one(void *num)
{
	int	*p;

	p = malloc(sizeof(int));
	if (!p)
		return NULL;
	*p = *(int *)num + 1;
	return (p);
}

void	setzero(void *num)
{
	free(num);
}


// 1.
// 	a = 10;
// 	node1 = ft_lstnew(&a);
// 	//head -> content doesn't have malloc'ed array, cant be freed
// 	ft_lstclear(&head, setzero);


int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new_head;

	int	a;
	int	b;
	int	c;

	a = 10;
	b = 20;
	c = 30;

	head = NULL;
	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	node3 = ft_lstnew(&c);
	new_head = NULL;
	
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	print_nodes(head);
	new_head = ft_lstmap(head, add_one, setzero);
	print_nodes(new_head);

	printf("address of head: %p\n", head);
	printf("address of new_head: %p\n", new_head);

	ft_lstclear(&head, NULL);
	ft_lstclear(&new_head, setzero);
}
*/
/*
Reflection:
1. when logic is correct but memory leaks, should go to 
ft_lstdelone or ft_lstclear, that responsible for free(). 
*/
