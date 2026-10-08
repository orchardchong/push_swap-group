/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:15:02 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:54:11 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Look at how many proptotypes need to be called and compiled each time,
no matter in this file 
or in the terminal command:
ccc ft_strtrim.c ft_strdup.c ft_substr.c ft_strlen.c ft_strlcpy.c

this is the REASON to make a library.
*/

static int	isset(int c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
1.
if start = 0 then isset(s1[start++], set), then
start will go extra 1 byte
2.
while (s1[++start] && isset(s1[start], set))
while (s1[end] && isset(s1[end--], set))

there is no need to do s1[++start] and s1[end] because
already did null check beforehand, and do't have to loop every char
in the given string, i stop whenever is not a char in set
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	start;
	size_t			end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return ((char *) s1);
	start = -1;
	len = ft_strlen(s1);
	end = len - 1;
	while (isset(s1[++start], set))
		len--;
	if (!len)
		return (ft_strdup(""));
	while (isset(s1[end--], set))
		len--;
	return (ft_substr(s1, start, len));
}
/*
#include <string.h>
#include <stdio.h>

void	check(const char *desc, char *result, const char *expected)
{
	if (!result)
	{
		printf("%-35s -> (NULL)  FAIL (allocation failed)\n", desc);
		return ;
	}
	if (strcmp(result, expected) != 0)
		printf("%-35s -> \"%s\"  FAIL (expected \"%s\")\n", desc, 
		result, expected);
	else
		printf("%-35s -> \"%s\"  PASS\n", desc, result);
	free(result);
}

int	main(void)
{
	// normal cases
	check("trim both sides",         ft_strtrim("  Hello World  ", " "), 
	"Hello World");
	check("trim left only",          ft_strtrim("  Hello", " "), "Hello");
	check("trim right only",         ft_strtrim("Hello  ", " "), "Hello");
	check("nothing to trim",         ft_strtrim("Hello", " "), "Hello");
	check("multiple set chars",      ft_strtrim("xxHelloxx", "x"), "Hello");
	check("set has multiple chars",  ft_strtrim("-*Hello*-", "-*"), "Hello");

	// edge cases
	check("empty s1",                ft_strtrim("", " "), "");
	check("empty set (no trimming)", ft_strtrim("  Hello  ", ""), "  Hello  ");
	check("entire string is set",    ft_strtrim("xxxx", "x"), "");
	check("single char, trimmed",    ft_strtrim("x", "x"), "");
	check("single char, kept",       ft_strtrim("a", "x"), "a");
	check("set chars not present",   ft_strtrim("Hello", "xyz"), "Hello");
	return (0);
}
*/
/*
VERSION
v1:
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	size_t			len;
	unsigned int	start;
	size_t	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return ((char *) s1);
	start = -1;
	len = ft_strlen(s1);
	end = len - 1;
	while (s1[++start] && isset(s1[start], set))
		len--;
	if (!len)
		return (ft_strdup(""));
	while (s1[end] && isset(s1[end--], set))
		len--;
 	trimmed = malloc(sizeof(char) * len + 1);
	if (!trimmed)
		return (0);
	trimmed = ft_substr(s1 , start, len);
	return (trimmed);	
}
	
*/