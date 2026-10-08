/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:11:44 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:48:35 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Why c must be cast to (char) before comparing (example: c = 128)
//
// Expression         | Raw value | Goes through char? | Final int value
// -------------------|-----------|---------------------|----------------
// *s (byte 0x80)     | 128       | yes (char is signed) | -128
// c   (no cast)      | 128       | no                   |  128
// (char)c            | 128       | yes (forced)          | -128
//
// *s == c        ->  -128 == 128   -> false   (WRONG - same byte, missed)
// *s == (char)c  ->  -128 == -128  -> true    (correct - matches real strchr)
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char) c == 0)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "Find a char in a string";
	char to_find = 'a';

	printf("%s\n", ft_strchr(s, to_find));
	printf("%s\n", strchr(s, to_find));
}
*/
