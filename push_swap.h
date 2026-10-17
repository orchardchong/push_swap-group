/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 20:49:24 by junlim            #+#    #+#             */
/*   Updated: 2026/10/17 18:29:25 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct s_node
{
	int				num;
	int				sorted_index;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}				t_stack;

//linked list manipulation
t_node	*ft_doubly_lstnew(int data);
void	ft_doubly_lstadd_back(t_stack *stack, t_node *new);
void	ft_doubly_lstadd_front(t_stack *stack, t_node *new);
void	ft_clearstack(t_stack *stack);

//operations
void	ra(t_stack *stack, int print_rr);
void	rb(t_stack *stack, int print_rr);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack, int print_rrr);
void	rrb(t_stack *stack, int print_rrr);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack, int print_ss);
void	sb(t_stack *stack, int print_ss);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

//radix and its utils
void	radix_sort(t_stack *a, t_stack *b, int max);
int		*get_int_arr(char **args, int size);
void	insertion_sort(int *arr, int size);
void	assign_sorted_index(t_stack *stack, int *sorted_array);
int		get_max_num_bits_count(int max);
int		count_matching_bit (t_stack *stack, int stacksize, int bit_pos, int bit);

//disorder metric
float	disorder_metrics(t_stack *stack_a);

//parsing
int		is_num(char *str);
long	ft_atol(const char *str);
int		check_duplicate(t_stack *stack_a, int digit);

//to free array & free node
void	free_array(char **array);
void	free_and_erase (t_stack *stack_a, char **array, int is_split);

//to check main
void	check_parsing_create_node(t_stack *stack_a, char **argv, int is_split);

#endif 