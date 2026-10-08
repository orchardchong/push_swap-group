/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:02:53 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:09:24 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*num;
	long int	long_n;
	int			count;

	long_n = n;
	count = count_chars(long_n);
	num = ft_calloc(count + 1, sizeof(char));
	if (!num)
		return (0);
	if (long_n < 0)
	{
		num[0] = '-';
		long_n *= -1;
	}
	if (long_n == 0)
		num[0] = '0';
	num[count] = '\0';
	while (long_n > 0)
	{
		num[--count] = long_n % 10 + '0';
		long_n /= 10;
	}
	return (num);
}

/*
#include <stdio.h>
#include <limits.h>
#include <string.h>

void	check(const char *desc, char *result, int n)
{
	char	expected[16];

	sprintf(expected, "%d", n); //convert n into its string representation

	if (strcmp(result, expected) != 0)
		printf("%-25s -> \"%s\"  FAIL (expected \"%s\")\n", desc, result, 
		expected);
	else
		printf("%-25s -> \"%s\"  PASS\n", desc, result);
	free(result);
}

int	main(void)
{
	check("zero",                 ft_itoa(0), 0);
	check("positive single digit", ft_itoa(7), 7);
	check("negative single digit", ft_itoa(-7), -7);
	check("positive multi-digit", ft_itoa(12345), 12345);
	check("negative multi-digit", ft_itoa(-12345), -12345);
	check("-1",                    ft_itoa(-1), -1);
	check("1",                     ft_itoa(1), 1);
	check("INT_MAX",               ft_itoa(INT_MAX), INT_MAX);
	check("INT_MIN",               ft_itoa(INT_MIN), INT_MIN);
	check("INT_MIN + 1",           ft_itoa(INT_MIN + 1), INT_MIN + 1);
	check("power of ten",          ft_itoa(1000000), 1000000);
	check("negative power of ten", ft_itoa(-1000000), -1000000);

	return (0);
}
*/