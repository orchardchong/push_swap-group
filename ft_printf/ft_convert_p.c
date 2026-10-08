/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 08:34:57 by junlim            #+#    #+#             */
/*   Updated: 2026/09/22 17:27:09 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_p(unsigned long n)
{
	char	*lower_hex_num;
	char	*address;
	int		len;

	if (!n)
	{
		ft_putstr_fd(NULL_PTR, 1);
		return (ft_strlen(NULL_PTR));
	}
	lower_hex_num = ft_utoa_base(n, LOWER_HEX_BASE);
	address = ft_strjoin(ADDRESS_PREFIX, lower_hex_num);
	len = ft_strlen(address);
	ft_putstr_fd(address, 1);
	free(lower_hex_num);
	free(address);
	return (len);
}
