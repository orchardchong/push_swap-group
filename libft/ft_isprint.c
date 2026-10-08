/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:11:18 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:30:08 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
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
	int sym1 = 154; // š in Ascii, cant use char because its more than 1 byte
	int sym2 = 0; // NULL

	printf("%c is ft_isprint? %d\n", c1, ft_isprint(c1));
	printf("%c is isprint? %d\n", c1, isprint(c1));
	printf("%c is ft_isprint? %d\n", c2, ft_isprint(c2));
	printf("%c is isprint? %d\n", c2, isprint(c2));
	printf("%c is ft_isprint? %d\n", c3, ft_isprint(c3));
	printf("%c is isprint? %d\n", c3, isprint(c3));
	printf("š is ft_isprint? %d\n", ft_isprint(sym1));
	printf("š is isprint? %d\n", isprint(sym1));
	printf("null is ft_isprint? %d\n", ft_isprint(sym2));
	printf("null is isprint? %d\n", isprint(sym2));
}
*/