/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:13:02 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:02:23 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	The memchr() function scans the initial n bytes of the memory area
	pointed to by s for the first instance of c.  Both c and the bytes
	of the memory area pointed to by s are interpreted as unsigned
	char.
*/
/*
	This function is about memory space, cannot terminate while loop using
	string logic.

	example 1:
	if ((char) c == 0)
		return ((char *)s);
	this is to return the last null because strchr expected a string input

	example 2:
	buffer: 'a' 'b' '\0' 'c' 'd'   (n = 5, searching for 'd')
	while (s_s[i] && i < n)   <-- BUGGY: stops when s_s[i] == '\0'
	ft_memchr returns NULL, but real memchr scans all 5 bytes and finds 'd'
*/
/*
void is necessary because of const unsigned char *, without const, it will
be implicitly converted to void * without the cast
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_s;
	unsigned char		c_c;
	size_t				i;

	s_s = s;
	c_c = c;
	i = 0;
	while (i < n)
	{
		if (s_s[i] == c_c)
			return ((void *) &s_s[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "Find a char in a string";
	char to_find = 'a';

	printf("%s\n", (char *) ft_memchr(s, to_find, 16));
	printf("%s\n", (char *) memchr(s, to_find, 16));

	char buf[] = {'a', 'b', 'c', '\0', 'd'};
	char c = 'd';
	char *p1 = ft_memchr(buf, c, 5);
	char *p2 = memchr(buf, c, 5);

	if (p1)
		printf("%c is found\n", *p1);
	else
		printf("Null\n");

	if (p2)
		printf("%c is found\n", *p2);
	else
		printf("Null\n");

}
*/