/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:29:12 by junlim            #+#    #+#             */
/*   Updated: 2026/10/22 19:29:12 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
get_next_line keeps unread input in its static stash. Reading until NULL
lets it free the stash, so exiting on Error does not leave it allocated.

Why a loop and not 1 call: lines can still come after the bad one.
Example, typed by hand:
	./checker 2 1 3
	bad⏎        <- invalid, read_and_apply calls drain_stdin
	pa⏎         <- typed before Ctrl+D
	^D

	call 1: returns "pa\n" (not NULL), freed. stash = "" (still malloc'd)
	call 2: read() gets EOF, stash "" is freed, returns NULL -> loop ends
With only 1 call, the "" stash from call 1 would leak (1 byte).
*/
static void	drain_stdin(void)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
}

//invalid instruction: free everything, then free_and_erase prints Error
static void	read_and_apply(t_stacks *s)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!apply_op(s, line))
		{
			free(line);
			drain_stdin();
			ft_clearstack(s->b);
			free_and_erase(s->a, NULL, 0);
		}
		free(line);
		line = get_next_line(0);
	}
}

//same argument parsing as push_swap's main, args freed before reading
static void	parse_args(t_stack *a, int argc, char **argv)
{
	char	**args;

	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (!args || !args[0])
		free_and_erase(a, args, argc == 2);
	check_parsing_create_node(a, args, argc == 2);
	if (argc == 2)
		free_array(args);
}

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_stacks	s;

	if (argc == 1)
		return (0);
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	parse_args(&a, argc, argv);
	s.a = &a;
	s.b = &b;
	read_and_apply(&s);
	if (is_sorted(&a) && b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_clearstack(&a);
	ft_clearstack(&b);
	return (0);
}
