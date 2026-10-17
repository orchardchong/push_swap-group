/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 20:49:24 by junlim            #+#    #+#             */
/*   Updated: 2026/10/17 21:58:30 by ochong           ###   ########.fr       */
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
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

//disorder metric
float	disorder_metrics(t_stack *stack_a);

//parsing
int		is_num(char *str);
long	ft_atol(const char *str);
int		check_duplicate(t_stack *stack_a, int digit);

//to free array & free node
void	free_array(char **array);
void	free_and_erase(t_stack *stack_a, char **array, int is_split);

//to check main
void	check_parsing_create_node(t_stack *stack_a, char **argv, int is_split);

//handle correct arguments
int		is_sorted(t_stack *stack_a);

//handle 3 arguments
int		sorted_three(t_stack *stack_a);

//simple algorithm
t_node	*get_min_node(t_stack *stack_a);
void	simple(t_stack *stack_a, t_stack *stack_b);
//void	adaptive_sort(t_stack *stack_a, t_stack *stack_b);
#endif 