/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:24:40 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:13:45 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. last must be initialized to null so that when *s is null, it will return
garbage value
2. this is slower when the string is longer because im not starting from behind

// len = strlen(s), NOT strlen(s) - 1: starting at the terminator's own
// index lets one loop handle both "find last char" AND c == '\0'
// strlen(s) - 1 will skips the null terminator

another imeplementation:
char	*ft_strrchr(const char *s, int c)
{
	int s_len; // using size_t will always makes the while loop true

	s_len = ft_strlen(s);

	while (s_len >= 0)
	{
		if (s[s_len] == (char) c)
			return ((char *) &s[s_len]);
		s_len--;
	}
	// this is redundant as now it starts cehcking from behind and while loop is
	// not stopped by '\0' anymore
	if ((char) c == 0) 
		return ((char *)s);
	return (0);
}
3. if address is used to iterate, then don't have to worry when int s_len is
not enough for longer strings
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char) c == 0)
		return ((char *)s);
	return ((char *) last);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "Find a char in a string";
	char to_find = 'a';

	printf("%s\n", ft_strrchr(s, to_find));
	printf("%s\n", strrchr(s, to_find));
}
*/