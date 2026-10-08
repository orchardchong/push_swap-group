/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 07:53:17 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:08:44 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
1.
new = malloc(sizeof(t_list *)); is to create a linkedlist, not a new node. And 
its actually a pointer of 8 bytes, this struct of 16 bytes (2 pointers).
so it will cause heap overflow.

2.
if (!new || !content)
		return (NULL);
is valid to have a content as NULL so that it could be replaced with values
later. no need to check 
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

/*
#include <stdio.h>

int	main(void)
{
	int	a = 42;
	t_list	*node;
	node = ft_lstnew(&a);
	if (!node)
		return (0);
	printf("%d\n", *(int *)node -> content);
	free(node);
}
*/