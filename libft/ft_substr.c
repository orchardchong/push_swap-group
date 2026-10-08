/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:55:31 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:53:09 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
CORRECTIONS
1. if ((size_t)start > ft_strlen(s) - 1)
ft_strlen returns size_t type, minus 1 will not result in (-1) the result of
expression actually also considered as size_t, so it wraps to SIZE_MAX
	ft_strlen(s) - 1 is to not let start become the null terminator index
	but its unncessary because ft_strlcpy will just copy "" into substr
	when s + start is pointing to null terminator, returning an empty
	string

FINDINGS
1. ft_strdup("") is used instead of "" because free() can only be used
with malloc(). if "" is returned then error occrus when free("")

REQUIREMENTS
return "" because i only return NULL when allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	remaining_s_len;
	size_t	substr_len;

	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	remaining_s_len = ft_strlen(s + start);
	if (remaining_s_len >= len)
		substr_len = len + 1;
	else
		substr_len = remaining_s_len + 1;
	substr = malloc(sizeof(char) * substr_len);
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, substr_len);
	return (substr);
}

/*
#include <stdio.h>
#include <string.h>

void check(char *desc, char *result, char *expected)
{
	printf("%-40s -> \"%s\" %s\n", desc, result,
		(result && strcmp(result, expected) == 0)? "PASS" : "FAIL");
	free(result);
}

int	main(void)
{
	check("normal substring",
		ft_substr("Hello World", 0, 5), "Hello");

	check("start mid-string",
		ft_substr("Hello World", 6, 5), "World");

	check("len exceeds remaining chars",
		ft_substr("Hello World", 6, 100), "World");

	check("start past end of string",
		ft_substr("Hello World", 100, 5), "");

	check("start == strlen(s) exactly",
		ft_substr("Hello World", 11, 5), "");

	check("len == 0",
		ft_substr("Hello", 0, 0), "");

	check("empty string, start = 0",
		ft_substr("", 0, 5), "");

	check("empty string, start > 0",
		ft_substr("", 1, 5), "");

	check("len exactly matches remaining",
		ft_substr("Hello World", 6, 5), "World");

	check("start = 0, len covers whole string",
		ft_substr("Hi", 0, 2), "Hi");

	return (0);
}
*/