/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:48:32 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:25:44 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main (void)
{
	char c1 = 'A';
	char c2 = '\t';
	char c3 = '*';
	// According to the manual,     
	// The values returned are nonzero if the character c falls into the
    //    tested class, and zero if not.
	// So isalpha doesn't necessarily returns 1
	
	printf("%c is ft_alpha? %d\n", c1, ft_isalpha(c1));
	printf("%c is isalpha? %d\n", c1, isalpha(c1));
	printf("%c is ft_alpha? %d\n", c2, ft_isalpha(c2));
	printf("%c is isalpha? %d\n", c2, isalpha(c2));
	printf("%c is ft_alpha? %d\n", c3, ft_isalpha(c3));
	printf("%c is isalpha? %d\n", c3, isalpha(c3));
}
*/