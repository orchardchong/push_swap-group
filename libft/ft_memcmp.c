/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:36:48 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:03:29 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1 = "abc";
	char *s2 = "abcd";
	unsigned int n;

	n = 3;
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);	
	printf("first %d characters is equal(= 0)?: %d\n", n, ft_memcmp(s1, s2, n));
	printf("standard memcmp?: %d\n", memcmp(s1, s2, n));
}
*/
