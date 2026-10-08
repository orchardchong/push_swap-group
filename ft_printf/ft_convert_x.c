/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:00:17 by junlim            #+#    #+#             */
/*   Updated: 2026/09/22 17:12:15 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_x(unsigned int n)
{
	char	*lowercase_hex_num;
	int		len;

	lowercase_hex_num = ft_utoa_base(n, LOWER_HEX_BASE);
	len = ft_strlen(lowercase_hex_num);
	ft_putstr_fd(lowercase_hex_num, 1);
	free(lowercase_hex_num);
	return (len);
}
