/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:29:12 by junlim            #+#    #+#             */
/*   Updated: 2026/10/23 22:38:03 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	read_and_apply(t_stacks *s)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!apply_op(s, line))
		{
			free(line);
			get_next_line(-1);
			ft_clearstack(s->b);
			ft_clearstack(s->a);
			ft_putstr_fd("Error\n", 2);
			exit(1);
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
/*HOW read() GIVES INPUT TO get_next_line (BUFFER_SIZE = 10)

read() only waits when nothing is available otherwise keep reading 
(man 3 termios).
https://man7.org/linux/man-pages/man3/termios.3.html

1. typing, line shorter than BUFFER_SIZE: "sa" + Enter
	read() waits until Enter, then returns "sa\n" (1 line per read).
2. typing, line longer than BUFFER_SIZE: "sass gde idjs" + Enter
	Enter puts all 14 bytes in the terminal buffer.
	read() -> "sass gde i" (no '\n', GNL's while loop reads again)
	read() -> "djs\n"      (no wait for user until finish reading)
3. piping: printf 'sa\nbad\nra\n' | ./checker 2 1 3
	read() -> sa\nbad\nra\n, returned -> sa\n, stash -> bad\nra\n, 

WHY THE STASH LEAKS ON Error
Case1: After every returned line, stash is still malloc'd: "".
Without next gnl() to accept EOF from user, "" is always there.
Just like using gnl() on files, after finish reading the content,
1 more call is needed to reach EOF, and free "".

Case3: if the piped input has a lot of \n, needs to drain_stdin()
Because every gnl() called only returned up to \n, if the stash needs
to be empty, 1 way is to repeatedly called gnl().

FIX: get_next_line(-1)
Reset the stash ourselves to prevent repeated calls like this:
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
It makes more sense to stop the program when input is wrong instead
of having to wait for EOF from user.
*/