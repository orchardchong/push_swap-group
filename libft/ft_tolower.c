/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:08:20 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:47:45 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%c", ft_tolower('a'));
	printf("%c", ft_tolower('A'));
	printf("%c", ft_tolower('1'));
}
*/