/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:51:35 by junlim            #+#    #+#             */
/*   Updated: 2026/08/16 08:46:14 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
while (i_big < len && big[i_big])
i_big < len is to stop executing the inner while loop earlier eventhough
the innger i_big + i_little < len is the same check. But its still safe 
to include it as it will stop properly when big is not null terminated
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;

	i_big = 0;
	i_little = 0;
	if (little[i_little] == '\0')
		return ((char *) big);
	while (i_big < len && big[i_big])
	{
		while (i_big + i_little < len
			&& big[i_big + i_little] == little[i_little])
		{
			i_little++;
			if (little[i_little] == '\0')
				return ((char *) &big[i_big]);
		}
		i_little = 0;
		i_big++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <bsd/string.h>


// Some cases to consider:
// 1.
// 	char *str = "hello, please target in this string. ?";
// 	char *to_find = "target";

// check when len = 15, whether is null or not. without i_big + i_little < len,
// then it woulld still return "target in this string. ?" 

// 2. check whether i_little is reset or not
// 		char *str = "hello, please tar cc get in this string. ?";
// 		char *to_find = "target";

// 	without reset, ft_strnstr: cc get in this string. ?


int	main(void)
{
	{
		char *str = "hello, please tar cc get in this string. ?";
		char *to_find = "target";
 
		printf("Test 0: Find target\n");
		printf("str: %s\n", str);
		printf("to_find: %s\n", to_find);
		printf("strnstr: %s\n", strnstr(str, to_find, 25));
		printf("ft_strnstr: %s\n", ft_strnstr(str, to_find, 25));
		printf("\n");

	}
}
*/
