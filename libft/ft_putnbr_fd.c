/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 01:15:31 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:06:18 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
whenever deal with functions that return address from heap:
1. must return to prevent memory leak. 
2. Also need to check whether is NULL to prevent crash
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (!nbr)
		return ;
	ft_putstr_fd(nbr, fd);
	free(nbr);
}

/*
#include <limits.h>

int	main(void)
{
	ft_putnbr_fd(0, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(7, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-7, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(12345, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-12345, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-1, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(1, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(INT_MAX, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(INT_MIN, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(INT_MIN + 1, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(1000000, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-1000000, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
*/
