/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:30:57 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:52:37 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
QUESTION: Why stddef.h for size_t is not needed here?
Although ft_strlen can be called whenever needed, if the string is too long,
extra calls will slow down the program. 

+1 to include null terminator
*/
char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	size_t	s1_cpy_len;

	s1_cpy_len = ft_strlen(s1) + 1;
	s1_cpy = malloc(sizeof(char) * s1_cpy_len);
	if (!s1_cpy)
		return (0);
	ft_strlcpy(s1_cpy, s1, s1_cpy_len);
	return (s1_cpy);
}

/*
#include <stdio.h>

int	main(void)
{
	char *s1 = "copy this string";
	printf("%s\n", ft_strdup(s1));
}
*/