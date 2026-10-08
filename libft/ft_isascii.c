/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:52:39 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:30:05 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
checks whether c is a 7-bit unsigned char value that fits
into the ASCII character set. so its 2^7 = 128 values. From Ascii table,
starting from 128 to 255 are extended ASCII codes.
*/
int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
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
	int sym = 154; // š in Ascii, cant use char because its more than 1 byte

	printf("%c is ft_isascii? %d\n", c1, ft_isascii(c1));
	printf("%c is isascii? %d\n", c1, isascii(c1));
	printf("%c is ft_isascii? %d\n", c2, ft_isascii(c2));
	printf("%c is isascii? %d\n", c2, isascii(c2));
	printf("%c is ft_isascii? %d\n", c3, ft_isascii(c3));
	printf("%c is isascii? %d\n", c3, isascii(c3));
	printf("š is ft_isascii? %d\n", ft_isascii(sym));
	printf("š is isascii? %d\n", isascii(sym));
}
*/
