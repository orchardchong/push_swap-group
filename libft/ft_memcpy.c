/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:35:53 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:01:42 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//does not handle memory areas that overlap
/*
	if (!dest || !src)
		return (dest);
	
	this is not added because its not necessary from the manual's
	standpoint
*/

/*
	while (n-- > 0)
	1. n > 0 is evaluated
	2. n--
	3. execute function body
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s_dst;
	const char	*s_src;

	s_dst = dest;
	s_src = src;
	while (n-- > 0)
		s_dst[n] = s_src[n];
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest1[20] = "This is destination"; // +1 for null
	char dest2[24] = "This is destination too"; // +1 for null
	char src_ft_memcpy[10] = "ft_memcpy"; // +1 for null
	char src_memcpy[7] = "memcpy"; // +1 for null

	printf("dest1: %s\n",dest1);
	ft_memcpy(dest1 + 8, src_ft_memcpy, 9);
	printf("dest1: %s\n",dest1);
	
	printf("dest2: %s\n",dest2);
	memcpy(dest2 + 8, src_memcpy, 6);
	printf("dest2: %s\n",dest2);
	return (0);
}
*/
