/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:39:46 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:27:17 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int main (void)
{
	char c1 = '3';
	char c2 = 'A';
	char c3 = '*';

	printf("%c is ft_isdigit? %d\n", c1, ft_isdigit(c1));
	printf("%c is isdigit? %d\n", c1, isdigit(c1));
	printf("%c is ft_isdigit? %d\n", c2, ft_isdigit(c2));
	printf("%c is isdigit? %d\n", c2, isdigit(c2));
	printf("%c is ft_isdigit? %d\n", c3, ft_isdigit(c3));
	printf("%c is isdigit? %d\n", c3, isdigit(c3));
}
*/
