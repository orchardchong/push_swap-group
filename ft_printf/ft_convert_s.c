/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:57:31 by junlim            #+#    #+#             */
/*   Updated: 2026/09/22 17:05:16 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_s(char *str)
{
	if (!str)
	{
		ft_putstr_fd(NULL_STR, 1);
		return (ft_strlen(NULL_STR));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

// int main (void)
// {
// 	ft_convert_s(NULL);
// }
/*edge cases
1. empty string
*/