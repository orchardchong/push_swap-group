/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:20:17 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:46:54 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// size_t has 8 bytes while int has 4 bytes to accomodate longer strings. 
//There won't be -ve num of chars
// const to make the string read only as this function only returns its length

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	char *s1 = "Count this string!";
	char *s2 = "";
	char *s3 = "(*)Ž";

	printf("%s's ft_strlen? %ld\n", s1, ft_strlen(s1));
	printf("%s's strlen? %ld\n", s1, strlen(s1));
	printf("%s's ft_strlen? %ld\n", s2, ft_strlen(s2));
	printf("%s's strlen? %ld\n", s2, strlen(s2));
	printf("%s's ft_strlen? %ld\n", s3, ft_strlen(s3));
	printf("%s's strlen? %ld\n", s3, strlen(s3));
}
*/