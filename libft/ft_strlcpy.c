/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:43:49 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:50:23 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Unlike those functions, strlcpy() and strlcat() take 
//the full size of the buffer (not just the length)
//so it stops cpying when dest buffer size is reached,
//preventing buffer overflow that will affects memory
//that comes after dest in stack/heap
/*
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

(dst_size > 0) and (dst_size) has functionally no difference,
main purpose is to copy when dst_size is not 0
*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	len;

	len = 0;
	if (dst_size > 0)
	{
		while (src[len] != '\0' && len < dst_size - 1)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{	
	char	dest1[15];
	char	src1[] = "get your crayon";
	char	dest2[15];
	char	src2[] = "get your crayon";
	size_t n; //‘size_t’ {aka ‘long unsigned int’}
	
	n = 10;

	printf("Before ft_strlcpy: \n");
	printf("dest: %s\n", dest1);
	printf("src: %s\n", src1);
	printf("Before strlcpy: \n");
	printf("dest: %s\n", dest1);
	printf("src: %s\n", src1);

	printf("\n");
	printf("ft_strlcpy src length: %ld\n", ft_strlcpy(dest1, src1, n));
	printf("strlcpy src length: %ld\n", strlcpy(dest2, src2, n));
	printf("\n");
	
	printf("After ft_strlcpy %ld characters: \n", n);
	printf("dest1: %s\n", dest1);
	printf("After strlcpy %ld characters: \n", n);
	printf("dest2: %s\n", dest2);
	printf("\n");

	return (0);
}
*/