/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:41:38 by junlim            #+#    #+#             */
/*   Updated: 2026/09/21 18:05:37 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_d_i(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	len = ft_strlen(num);
	ft_putstr_fd(num, 1);
	free(num);
	return (len);
}

// int main(void)
// {
// 	ft_convert_d_i(-12345);
// }