/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:36:57 by ochong            #+#    #+#             */
/*   Updated: 2026/10/19 20:36:57 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_bench_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_bench *bench)
{
	int	front_digit;
	int	decimal;

	if (bench == NULL || bench->active == 0)
		return;
	front_digit = (int)(bench->disorder * 100);
	decimal = (int)(bench->disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(front_digit, 2);
	ft_putstr_fd(".", 2);
	if (decimal < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (bench->strategy == 0)
		ft_putstr_fd("Adaptive / Auto\n", 2);
	else if (bench->strategy == 1)
		ft_putstr_fd("Simple O(n^2)\n", 2);
	else if (bench->strategy == 2)
		ft_putstr_fd("Medium O(n√n)\n", 2);
	else if (bench->strategy == 3)
		ft_putstr_fd("Complex O(n log n)\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_bench_ops(bench);
}

/*int main(void)
{
	t_bench bench;

	bench.active = 1;
	bench.disorder = 0.1325;

	bench.strategy = 2;

	bench.total_ops = 2921;
	bench.sa = 100; bench.sb = 10; bench.ss = 100;
	bench.pa = 100; bench.pb = 100;
	bench.ra = 300; bench.rb = 200; bench.rr = 100;
	bench.rra = 200; bench.rrb = 712; bench.rrr = 999;

	print_benchmark(&bench);

	return (0);
}*/
