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
	ft_printf(2,"[bench] disorder: %d%\n", bench->disorder *100);
	ft_print(2,"[bench] strategy: ");
	if (bench->strategy == 0)
		ft_print (2, "Adaptive / 0 (n )")
}