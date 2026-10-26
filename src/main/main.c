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

#include "push_swap.h"

//argv++ skip the ./a.out
//remove the ./a.out so the total arguments will minus 1
//the first if is to handle --bench --simple
//by putting bench->strategy != 0 is to say we definitely have a flag 
//sitting at the front of the line. Chop it off!

static void	check_flags(int *argc, char ***argv, t_bench *bench)
{
	if (*argc > 1 && ft_strncmp((*argv)[1], "--bench", 8) == 0)
	{
		bench->active = 1;
		(*argv)++;
		(*argc)--;
	}
	if (*argc > 1 && ft_strncmp((*argv)[1], "--simple", 9) == 0)
		bench->strategy = 1;
	else if (*argc > 1 && ft_strncmp((*argv)[1], "--medium", 9) == 0)
		bench->strategy = 2;
	else if (*argc > 1 && ft_strncmp((*argv)[1], "--complex", 10) == 0)
		bench->strategy = 3;
	if (bench->strategy != 0
		|| (*argc > 1 && ft_strncmp((*argv)[1], "--adaptive", 11) == 0))
	{
		(*argv)++;
		(*argc)--;
	}
}

static void	sorting_exercution(t_stack *stack_a, t_stack *stack_b,
	char **args, t_bench *bench)
{
	if (FORCE_STRAT != 0)
		bench->strategy = FORCE_STRAT;
	if (stack_a->size <= 5)
	{
		bench->strategy = 4;
		small_sort(stack_a, stack_b, bench);
	}
	else if (bench->strategy == 1)
		selection (stack_a, stack_b, bench);
	else if (bench->strategy == 2)
		chunk_sort (stack_a, stack_b, args, bench);
	else if (bench->strategy == 3)
		radix_sort (stack_a, stack_b, args, bench);
	else
		adaptive_sort (stack_a, stack_b, args, bench);
}

/*void	print_array(int *array, int size)
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
}

void	print_doubly(t_stack *a)
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
}*/

static void	initialize_data(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	stack_a->top = NULL;
	stack_a->size = 0;
	stack_b->top = NULL;
	stack_b->size = 0;
	ft_bzero(bench, sizeof(t_bench));
}

//check ./a.out "1 2 3"
//start from 1: 4[1] 5[2] 6[3], not ./a.out

//check_parsing_create_node(&stack_a, args, argc == 2);,
//it asks the compiler: "Does 4 equal 2?"

//to check is it sorted in 1 2 3, It drops straight down to
//print_benchmark(&bench);. Because no physical moves were made
//then it will print total_ops: 0 and disorder: 0.00%.

//to check is it sorted in 1 2 3? do ft_clearstack 
//to check is it sorted in "1 2 3" do ft_clearstack & free_array
//ft_clearstack always exist because of node is created

//to check "" or "   ": ft_split returns [NULL] (no words), not NULL,
//so check_parsing_create_node loops 0 times and no Error is printed.
//!args catches ft_split malloc fail, !args[0] catches no numbers.

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_bench	bench;
	char	**args;

	initialize_data(&stack_a, &stack_b, &bench);
	if (argc == 1)
		return (0);
	check_flags (&argc, &argv, &bench);
	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	check_parsing_create_node(&stack_a, args, argc == 2);
	if (is_sorted(&stack_a) == 0)
	{
		bench.disorder = disorder_metrics(&stack_a);
		sorting_exercution (&stack_a, &stack_b, args, &bench);
	}
	print_benchmark(&bench);
	if (argc == 2)
		free_array(args);
	ft_clearstack(&stack_a);
	return (0);
}
