/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:33:24 by junlim            #+#    #+#             */
/*   Updated: 2026/10/04 10:44:44 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DECIMAL_BASE "0123456789"
# define LOWER_HEX_BASE "0123456789abcdef"
# define UPPER_HEX_BASE "0123456789ABCDEF"
# define ADDRESS_PREFIX "0x"
# define NULL_STR "(null)"
# define NULL_PTR "(nil)"

# include "libft.h"
# include "stdarg.h"

int		ft_convert_c(int c);
int		ft_convert_s(char *str);
int		ft_convert_p(unsigned long n);
int		ft_convert_d_i(int n);
int		ft_convert_u(unsigned int n);
int		ft_convert_x(unsigned int n);
int		ft_convert_upper_x(unsigned int n);
int		ft_printf(const char *str, ...);

char	*ft_utoa_base(unsigned long n, char *base);

#endif