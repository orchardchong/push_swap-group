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

void	print_benchmark(t_bench *bench)
{
	if(bench == NULL || bench->active == 0)
		return;
	ft_printf("[bench] disorder: %d%\n", bench->disorder *100);
	ft_print(2,"[bench] strategy: ");
	if (bench->strategy == 0)
		ft_printf("Adaptive / Auto\n");
	if (bench->strategy == 1)
		ft_printf("Simple O(n²)\n");
	if (bench->strategy == 2)
		ft_printf("Medium O(n√n)\n");
	if (bench->strategy == 3)
		ft_printf("Complex O(n log n)");
	ft_printf("[bench] total_ops: %d\n", bench->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
			bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
			bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
