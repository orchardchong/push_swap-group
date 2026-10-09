/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_clear_and_erase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:40:29 by ochong            #+#    #+#             */
/*   Updated: 2026/10/06 00:40:29 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	free_array(char **array) //this is to free ./a.out "1 2 3 a"
{
	int	i;

	i = 0;
	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
//is_split (1) meaning yes, it is created by ft_split "1 2 3", if no means:1 2 3 (created by argv)
void	free_and_erase (t_stack *stack_a, char **array, int is_split)
{
	if (stack_a != NULL && stack_a->top != NULL)
		ft_clearstack(stack_a);
	if (is_split == 1 && array != NULL && *array != NULL)
		free_array(array);
	write (2, "Error\n", 6);
	exit(1);
}

/*#include <stdio.h>
int main(void)
{
	t_stack	stack_a;
	char	**fake_array;
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(42)); 
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(24));
	ft_doubly_lstadd_back(&stack_a, ft_doubly_lstnew(99));

	fake_array = ft_split("1 2 3", ' ');
	printf("Memory allocated for stack_a and fake_array.\n");
	printf("Triggering free_and_erase...\n");
	free_and_erase(&stack_a, fake_array, 0);
	printf("If you see this, free_and_erase failed to exit!\n");
	return (0);
}*/
