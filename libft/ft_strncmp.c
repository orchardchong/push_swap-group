/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:43:28 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:51:48 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	char *s1 = "abc";
	char *s2 = "abcd";

in this case without if(i == n), it will compare s1's null and s2's d.
if(i == n) if i can compare up to n bytes, means every thing is the same
*/
/*
unsigned char comparison is required according to the manual, if not
the range is different and causes inconsistencies.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
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
	printf("first %d characters is equal(= 0)?: %d\n", n, ft_strncmp(s1, s2, n));
	printf("standard strnmp?: %d\n", strncmp(s1, s2, n));
}
*/
