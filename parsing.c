/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 01:28:34 by ochong            #+#    #+#             */
/*   Updated: 2026/10/03 01:28:34 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check is it a real number
int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0') //how should it handle "- 2"? ft_split will handle
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

//using long just to handle overflow or underflow like 999999999999
long	ft_atol(const char *str)
{
	int		i;
	int		symbol;
	long	num;

	i = 0;
	symbol = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			symbol = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * symbol);
}

//each num only can show up once '0' means no duplicates, '1' means yes, there is a duplicate
int	check_duplicate(t_stack *stack_a, int digit)
{
	t_node	*current;

	if (stack_a == NULL || stack_a->top == NULL)
		return (0);
	current = stack_a->top;
	while (current->next != stack_a->top)
	{
		if (current->num == digit)
			return (1);
		current = current->next;
	}
	if (current->num == digit)
		return (1);
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	printf("To test is_num\n");
	printf("'123'  -> %d (Expected: 1)\n", is_num("123"));
	printf("'-42'  -> %d (Expected: 1)\n", is_num("-42"));
	printf("'- 2'  -> %d (Expected: 0)\n", is_num("- 2"));
	printf("'12a3' -> %d (Expected: 0)\n", is_num("12a3"));
	printf("'+9'   -> %d (Expected: 1)\n", is_num("+9"));

	printf("To test ft_atol\n");
	printf("'2147483647'   -> %ld\n", ft_atol("2147483647"));
	printf("'-2147483648'  -> %ld\n", ft_atol("-2147483648"));
	printf("'999999999999' -> %ld \n", ft_atol("999999999999"));

	printf("To check duplicates\n");
	t_stack	stack_a = NULL;
	t_node	node1;
	t_node	node2;

	node1.num = 1;
	node2.num = 2;

	node1.next = &node2;
	node1.prev = &node2;
	node2.next = &node1;
	node2.prev = &node1;

	stack_a.top = &node1;
	stack_a.size = 2;

	printf("Stack currently contains: [1, 2]\n");
	printf("Checking for 1 -> %d (Expected: 1 - Duplicate found)\n", check_duplicate(&stack_a, 1));
	printf("Checking for 2 -> %d (Expected: 1 - Duplicate found)\n", check_duplicate(&stack_a, 2));
	printf("Checking for 6 -> %d (Expected: 0 - Safe to add)\n", check_duplicate(&stack_a, 6));
	return (0);
}*/
