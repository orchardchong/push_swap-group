/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:14:45 by junlim            #+#    #+#             */
/*   Updated: 2026/09/22 09:01:56 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_chars(long unsigned n, int base_len)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= base_len;
	}
	return (count);
}

static int	is_base_valid(char *base)
{
	int		i;
	size_t	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= 32 || base[i] > 126)
			return (0);
		j = 1 + i;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_utoa_base(unsigned long n, char *base)
{
	char		*num;
	int			count;

	if (!is_base_valid(base))
		return (0);
	count = count_chars(n, ft_strlen(base));
	num = ft_calloc(count + 1, sizeof(char));
	if (!num)
		return (0);
	if (n == 0)
		num[0] = '0';
	num[count] = '\0';
	while (n > 0)
	{
		num[--count] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (num);
}
/*
int main(void)
{
	printf("%u\n", -5);	
	printf("%s", ft_utoa_base(-5 ,"0123456789"));
}
*/
/*Edge cases
1. duplicate base values
2. less than 2 digit base
*/