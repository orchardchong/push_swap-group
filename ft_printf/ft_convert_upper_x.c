/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:03:25 by junlim            #+#    #+#             */
/*   Updated: 2026/09/22 17:12:48 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_upper_x(unsigned int n)
{
	char	*uppercase_hex_num;
	int		len;

	uppercase_hex_num = ft_utoa_base(n, UPPER_HEX_BASE);
	len = ft_strlen(uppercase_hex_num);
	ft_putstr_fd(uppercase_hex_num, 1);
	free(uppercase_hex_num);
	return (len);
}
