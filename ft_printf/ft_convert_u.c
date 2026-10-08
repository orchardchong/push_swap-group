/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:48:30 by junlim            #+#    #+#             */
/*   Updated: 2026/09/22 09:05:08 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_u(unsigned int n)
{
	char	*unsigned_num;
	int		len;

	unsigned_num = ft_utoa_base(n, DECIMAL_BASE);
	len = ft_strlen(unsigned_num);
	ft_putstr_fd(unsigned_num, 1);
	free(unsigned_num);
	return (len);
}
