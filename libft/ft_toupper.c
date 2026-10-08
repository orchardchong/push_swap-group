/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:03:43 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:49:41 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%c", ft_toupper('a'));
	printf("%c", ft_toupper('A'));
	printf("%c", ft_toupper('1'));
}
*/