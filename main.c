/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 01:01:27 by ochong            #+#    #+#             */
/*   Updated: 2026/10/07 01:01:27 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "push_swap.h"

void	check_parsing_create_node(t_stack *stack_a, char **argv, int is_split)
{
	t_node	*new_node;
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!is_num(argv[i])) //1 2 a %
			free_and_erase(stack_a, argv, is_split);
		num = ft_atol(argv[i]);
		if ((num > 2147483647) || (num < -2147483648))
			free_and_erase(stack_a, argv, is_split);
		if (check_duplicate(stack_a, num)) //1 2 2 3
			free_and_erase(stack_a, argv, is_split);
		new_node = ft_doubly_lstnew((int)(num));
		if (!new_node)
			free_and_erase(stack_a, argv, is_split);//added this for safety check)
		ft_doubly_lstadd_back(stack_a, new_node);
			//ft_doubly_lstadd_back(stack_a, ft_doubly_lstnew((int(num))));
		i++;
	}
}

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	ft_printf("arr: ");
	while (i < size)
	{
		ft_printf("%d ", array[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack_confirm(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return ;
	current = stack->top;
	printf("Stack A: ");
	while (current->next != stack->top)
	{
		printf("%d -> ", current->num);
		current = current->next;
	}
	printf("%d\n", current->num);
}*/

/*void	print_doubly(t_stack *a)
{
	t_node* current;

	ft_printf("Parsing Success! Size: %d\n", a->size);
	if (a->top != NULL)
	{
		current = a->top;
		ft_printf("Stack A: ");
		while (current->next != a->top)
		{
			ft_printf("%d (%d) -> ", current->num, current->sorted_index);
			current = current->next;
		}
		ft_printf("%d (%d)\n ", current->num, current->sorted_index);
	}
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_bench	bench;
	char	**args;
	int		is_split; //to check "1 2" or 1 2
	int		strategy;
	int		*arr;
	// t_node	*current;
	


	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;
	is_split = 0;
	strategy = 0;
	arr = NULL;
	ft_bzero(&bench, sizeof(t_bench));
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (ft_strncmp(argv[1], "--bench", 8) == 0)
	{
		bench.active = 1;
		argv++;
		argc--; 
	}
	if (ft_strncmp(argv[1], "--simple", 9) == 0) //==0 meaning perfectly match
	{
		strategy = 1;
		argv++; //skip the ./a.out
		argc--; //remove the ./a.out so the total arguments will minus 1
	}
	else if (ft_strncmp(argv[1], "--medium", 9)== 0)
	{
		strategy = 2;
		argv++;
		argc--;
	}
	else if (ft_strncmp(argv[1], "--complex", 10) == 0)
	{
		strategy = 3;
		argv++;
		argc--;
	}
	else if (ft_strncmp(argv[1], "--adaptive", 11)== 0)
	{
		strategy = 0;
		argv++;
		argc--;
	}
	if (argc == 2)
	{
		args = ft_split(argv[1], ' '); //check ./a.out "1 2 3"
		is_split = 1;
	}
	else
	{
		args = argv + 1; //start from 1: 4[1] 5[2] 6[3], not ./a.out
		is_split = 0;
	}
	check_parsing_create_node(&stack_a, args, is_split);
	// radix_sort(&stack_a, &stack_b, args);
	//chunk_sort(&stack_a, &stack_b, args);
	// print_doubly(&stack_a);
	if (is_split == 1) //If parsing succeeds, clean up ft_split here safely
		free_array(args);

	if (is_sorted(&stack_a) == 1)
	{
		ft_clearstack(&stack_a);
		free(arr);
		return (0);
	}
	if (strategy == 1)
		selection(&stack_a, &stack_b, &bench);
	else if (strategy == 2)
		chunk_sort(&stack_a, &stack_b, &bench);
	else if (strategy == 3)
		radix_sort(&stack_a, &stack_b, arr[stack_a.size - 1], &bench);
	else
		adaptive_sort(&stack_a, &stack_b, , args, &bench);
	print_benchmark(&bench);
	// print_doubly(&stack_a);
	ft_clearstack(&stack_a);
	return (0);
}

int	main(void)
{
	t_stack	stack_a;
	t_node	*current;

	char *fake_argv[] = {"42", "-5", "99", NULL};
	stack_a.top = NULL;
	stack_a.size = 0;

	printf("Testing parsing with inputs: 42, -5, 99\n");
	check_parsing_create_node(&stack_a, fake_argv);
	
	printf("Parsing successful!\n");
	printf("Total size: %d\n", stack_a.size);
	if (stack_a.size > 0)
	{
		current = stack_a.top;
		printf("Stack contents: ");
		while (current->next != stack_a.top)
		{
			printf("%d -> ", current->num);
			current = current->next;
		}
		printf("%d\n", current->num);
	}
	return (0);
}*/
