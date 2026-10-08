/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:44:48 by junlim            #+#    #+#             */
/*   Updated: 2026/08/16 11:45:01 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	checks for white-space characters.  In the "C" and "POSIX"
	locales, these are: space, form-feed ('\f'), newline
	('\n'), carriage return ('\r'), horizontal tab ('\t'), and
	vertical tab ('\v').
*/

static int	isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while (isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
		sum = sum * 10 + s[i++] - 48;
	return (sign * sum);
}

/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*nb = "\0";

	printf("test case 0\n");
	printf("Given num in string: %s\n", nb);
	printf("ft_atoi: %d\n", ft_atoi(nb));
	printf("atoi: %d\n", atoi(nb));
	printf("-------------------------------------------\n");
	
	{
		char *string_num = "  \t\n 1234";
 
		printf("test case 1\n");
		printf("give num in string: %s\n", string_num);
		printf("ft_atoi: %d\n", ft_atoi(string_num));
		printf("atoi: %d\n", atoi(string_num));
		printf("-------------------------------------------\n");
	}
 
	{
		char *string_num = "   +-";
 
		printf("test case 3\n");
		printf("give num in string: %s\n", string_num);
		printf("ft_atoi: %d\n", ft_atoi(string_num));
		printf("atoi: %d\n", atoi(string_num));
		printf("-------------------------------------------\n");
	}
 
	{
		char *string_num = "21474836499";
 
		printf("test case 4\n");
		printf("give num in string: %s\n", string_num);
		printf("ft_atoi: %d\n", ft_atoi(string_num));
		printf("atoi: %d\n", atoi(string_num));
		printf("-------------------------------------------\n");
	}
}
*/
