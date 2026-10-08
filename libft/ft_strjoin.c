/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:38:07 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:53:39 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
concat_s[0] = '\0';
this is important because malloc() doesn't guarantee "clean" space, that's why
memset() or bzero() is important as we can start in a initial state that
we expected. Without this, in ft_strlcat, 	dst_len = ft_strlen(dst) will
find the length of garbage values until '\0' is met.

bzero is safe because it make sure there are no garbage values in the
allocated space. the current ft_strjoin allocates every space with
proper values, replacing every garbage value.
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_s;
	size_t	concat_len;

	concat_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	concat_s = malloc(sizeof(char) * concat_len);
	if (!concat_s)
		return (NULL);
	concat_s[0] = '\0';
	ft_strlcat(concat_s, s1, concat_len);
	ft_strlcat(concat_s, s2, concat_len);
	return (concat_s);
}

/*
#include <stdio.h>
#include <string.h>

void	check(const char *desc, char *result, const char *expected)
{
	if (!result)
	{
		printf("%-75s -> (NULL)  FAIL (allocation failed)\n", desc);
		return ;
	}
	if (strcmp(result, expected) != 0)
		printf("%-75s -> \"%s\"  FAIL (expected \"%s\")\n", desc, 
		result, expected);
	else
		printf("%-75s -> \"%s\"  PASS\n", desc, result);
	free(result);
}

int	main(void)
{
	//Happens when memory space is not correctly initialized and contains
	//garbage values
	check("Remove concat_s[0] = \'\\0\' will fail tests on non-fresh memory", 
			ft_strjoin("Hello ", "World"), "Hello World");

	// Standard edge cases
	check("normal join", ft_strjoin("Hello ", "World"), "Hello World");
	check("empty s1", ft_strjoin("", "World"), "World");
	check("empty s2", ft_strjoin("Hello ", ""), "Hello ");
	check("both empty", ft_strjoin("", ""), "");
	check("single chars", ft_strjoin("a", "b"), "ab");
	check("s1 longer than s2", ft_strjoin("aaaaaaaaaa", "b"), "aaaaaaaaaab");
	check("s2 longer than s1", ft_strjoin("a", "bbbbbbbbbb"), "abbbbbbbbbb");

	return (0);
}
*/