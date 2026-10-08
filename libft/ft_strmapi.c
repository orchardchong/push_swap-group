/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:57:42 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 22:10:40 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
C doesn't guarantee which function argument get evaluated first:
	while (s[i])
		str[i] = f(i, s[i++]);
this may be undefined and produce unexpected results.

when unsigned int i = -1, it doesn't matter for overflow as long
as ++i sets it back to 0
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = -1;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (0);
	while (s[++i])
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}

/*
char	odd_toupper(unsigned int i, char c)
{
	if (i % 2 != 0)
		return (ft_toupper(c));
	return (c);
}

#include <stdio.h>

int	main(void)
{
	char *str = "AbCdE";
	printf("Original: %s\n", str);
	printf("After applying function: %s\n", ft_strmapi(str, odd_toupper));
	return (0);
}
*/
