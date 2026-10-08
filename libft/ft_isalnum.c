/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:44:14 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:30:07 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main (void)
{
	char c1 = '3';
	char c2 = 'A';
	char c3 = '*';

	printf("%c is ft_isalnum? %d\n", c1, ft_isalnum(c1));
	printf("%c is isalnum? %d\n", c1, isalnum(c1));
	printf("%c is ft_isalnum? %d\n", c2, ft_isalnum(c2));
	printf("%c is isalnum? %d\n", c2, isalnum(c2));
	printf("%c is ft_isalnum? %d\n", c3, ft_isalnum(c3));
	printf("%c is isalnum? %d\n", c3, isalnum(c3));
}
*/