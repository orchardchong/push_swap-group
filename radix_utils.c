/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 08:17:19 by junlim            #+#    #+#             */
/*   Updated: 2026/10/17 09:04:36 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// free!
int	*get_int_arr(char **args, int stacksize)
{
	int	*arr;
	int	i;

	arr = ft_calloc(stacksize, sizeof(int));
	if (!arr)
		return (NULL);
	while (args[i])
	{
		arr[i] = ft_atol(args[i]);
		i++;
	}
	return (i);
}
