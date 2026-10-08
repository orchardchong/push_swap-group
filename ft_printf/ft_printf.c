/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:07:24 by junlim            #+#    #+#             */
/*   Updated: 2026/10/04 12:58:14 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_spec(char c, va_list args)
{
	if (c == 'c')
		return (ft_convert_c(va_arg(args, int)));
	else if (c == 's')
		return (ft_convert_s(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_convert_p(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_convert_d_i(va_arg(args, int)));
	else if (c == 'u')
		return (ft_convert_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_convert_x(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_convert_upper_x(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_convert_c('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_handle_spec(str[++i], args);
		else
			len += ft_convert_c(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*TESTS
1. with no specifier
2. with non-existing specifier
3. each specifier edge cases
*/
// #include <stdio.h>
// int	main(void)
// {
// 	{
// 		char	*test_name = "no specifier";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: abcdef\n");
// 		int		printf_value = printf("std: abcdef\n");
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	// {
// 	// 	char	*test_name = "non existing specifier";
// 	// 	printf("---------------- %s ----------------\n", test_name);
// 	// 	int		returned_value = ft_printf("test %w cde\n");
// 	// 	// int		printf_value = printf("std: %w\n");
// 	// 	printf("returned len: %d\n", returned_value);
// 	// 	// printf("printf's len: %d\n", printf_value);
// 	// }

// 	// ---------------%------------------------------
// 	{
// 		char	*test_name = "% conversion";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: print %%\n");
// 		int		printf_value = printf("std: print %%\n");
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	// ---------------CHAR------------------------------
// 	{
// 		char	*test_name = "char conversion - printable";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: print char %c\n", 42);
// 		int		printf_value = printf("std: print char %c\n", 42);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	//standard printf still counts the non-printable char
// 	{
// 		char	*test_name = "char conversion - non printable";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: print char %c\n", 30);
// 		int		printf_value = printf("std: print char %c\n", 30);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	// 577 - 256 = 321 -> 321 - 256 -> 65. if -ve value then + 256
// 	{
// 		char	*test_name = "char conversion - > 256";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: print char %c\n", 577);
// 		int		printf_value = printf("std: print char %c\n", 577);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "char conversion - multiple args";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int	ret_value = ft_printf("ft_: print char %c, %c, %c\n", 65, 66, 67);
// 		int	printf_value = printf("std: print char %c, %c, %c\n", 65, 66, 67);
// 		printf("returned len: %d\n", ret_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	// ---------------STRING------------------------------
// 	{
// 		char	*test_name = "string conversion - empty string";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: print string %s\n", "");
// 		int		printf_value = printf("std: print string %s\n", "");
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "string conversion - null";
// 		char	*str = NULL;
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: print string %s\n", NULL);
// 		int		printf_value = printf("std: print string %s\n", str);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "string conversion - multiple args";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int	ret_value = ft_printf("ft_:  %s, %s\n", "65", "try");
// 		int	printf_value = printf("std:  %s, %s\n", "65", "try");
// 		printf("returned len: %d\n", ret_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	// ---------------POINTER------------------------------
// 	{
// 		char	*test_name = "pointer conversion - null";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %p\n", NULL);
// 		int		printf_value = printf("std: %p\n", NULL);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "pointer conversion - 1 pointer";
// 		int		a = 10;
// 		int		*p = &a;
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %p\n", p);
// 		int		printf_value = printf("std: %p\n", p);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "pointer conversion - 3 pointers";
// 		int		a = 10;
// 		int		b = 11;
// 		int		c = 12;
// 		int		*p1 = &a;
// 		int		*p2 = &b;
// 		int		*p3 = &c;
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %p, %p, %p\n", p1, p2, p3);
// 		int		printf_value = printf("std: %p, %p, %p\n", p1, p2, p3);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	// ---------------Integers------------------------------
// 	{
// 		char	*test_name = "integer conversion - 0";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %d\n", 0);
// 		int		printf_value = printf("std: %d\n", 0);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "integer conversion - INT_MAX";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %d\n", 2147483647);
// 		int		printf_value = printf("std: %d\n", 2147483647);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	// standard's printf doesn't check for int_min
// 	// {
// 	// 	char	*test_name = "integer conversion - INT_MIN";
// 	// 	printf("---------------- %s ----------------\n", test_name);
// 	// 	int		returned_value = ft_printf("ft_: %i\n", -2147483648);
// 	// 	int		printf_value = printf("std: %i\n", -2147483648);
// 	// 	printf("returned len: %d\n", returned_value);
// 	// 	printf("printf's len: %d\n", printf_value);
// 	// }
// 	{
// 		char	*test_name = "integer conversion - multiple args with d/i spec";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %i, %d, %d\n", 3, -4, 5);
// 		int		printf_value = printf("std: %d, %i, %d\n", 3, -4, 5);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	// ---------------Unsigned Integers------------------------------
// 	{
// 		char	*test_name = "unsigned integer conversion - 0";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %u\n", 0);
// 		int		printf_value = printf("std: %u\n", 0);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 		{
// 		char	*test_name = "unsigned integer conversion - negative";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %u\n", -5);
// 		int		printf_value = printf("std: %u\n", -5);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	{
// 		char	*test_name = "unsigned integer conversion - multiple";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %u, %u, %u\n", 42, 43, 44);
// 		int		printf_value = printf("std: %u, %u, %u\n", 42, 43, 44);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	// ---------------Lower Hex------------------------------
// 	{
// 		char	*test_name = "lower hexa conversion - 0";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %x\n", 0);
// 		int		printf_value = printf("std: %x\n", 0);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	{
// 		char	*test_name = "lower hexa conversion - negative";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %x\n", -5);
// 		int		printf_value = printf("std: %x\n", -5);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "lower hexa conversion - multiple";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		ret = ft_printf("ft_: %x, %x, %x\n", 3, 92, 2147483647);
// 		int		printf_value = printf("std: %x, %x, %x\n", 3, 92, 2147483647);
// 		printf("returned len: %d\n", ret);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	// ---------------Upper Hex------------------------------
// 	{
// 		char	*test_name = "upper hexa conversion - 0";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %X\n", 0);
// 		int		printf_value = printf("std: %X\n", 0);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// 	{
// 		char	*test_name = "upper hexa conversion - negative";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int		returned_value = ft_printf("ft_: %X\n", -5);
// 		int		printf_value = printf("std: %X\n", -5);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}

// 	{
// 		char	*test_name = "upper hexa conversion - multiple";
// 		printf("---------------- %s ----------------\n", test_name);
// 		int	returned_value = ft_printf("ft_: %X, %X, %X\n", 3, 92, 2147483647);
// 		int	printf_value = printf("std: %X, %X, %X\n", 3, 92, 2147483647);
// 		printf("returned len: %d\n", returned_value);
// 		printf("printf's len: %d\n", printf_value);
// 	}
// }
/*FINDINGS
va_arg will promote char to int
*/

/*NOTES
1. doesn't check for string literal. compiler did check for printf. 
https://gcc.gnu.org/onlinedocs/gcc-3.1/gcc/Warning-Options.html

2. doesn't check for unknown specifier, skipped them.

3. overflow basics
if range from:
-3 -2 -1 0 1 2 

and i have value 10, the wrap around would be 10-6=4 (>2 so -6 again)
4 - 6 = -2.

visuals:

-3 -2 -1  0  1   2 <- real range is only -3 to 2
3   4  5  6  7   8 <- if every range value + 6
9  10 11 12	 13  14
...
vertically if we - number of values in the range, we will get the
smallest representation. For example 10, 10-6-6 maps to -2.

4. doesnt check for no matching argument (undefined)

*/