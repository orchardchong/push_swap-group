/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:25:01 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:01:21 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		*(str + i++) = '\0';
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[32] = "This is to learn about bzero()"; // +1 for null
	ft_bzero(str + 15, 5);
	// printf stops at the first null thats the end of string
	printf("ft_bzero: %s\n",str);
	bzero(str + 15, 5);
	printf("bzero: %s\n",str);
	return (0);
}
*/