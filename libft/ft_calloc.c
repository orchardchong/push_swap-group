/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 21:31:27 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 21:03:54 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
If the size of the
space requested is 0, the behavior is implementation-defined:
either a null pointer shall be returned, or the behavior shall be
as if the size were some non-zero value, except that the behavior
is undefined if the returned pointer is used to access an object.

return 1 so that there is always a unique pointer value to be freed instead
of depending on implementation.

since the allocation will use the result of size_t multiplcation, it might
overflow SIZE_MAX (max of size_t), need a guard to prevent this happens

(size_t)-1 will flip all the 64 bits to 1, so its SIZE_MAX

Example of 8 bits:

0000 0001

Flip
1111 1110

Add 1
1111 1111

Read as signed (int8):    -1
Read as unsigned (uint8): 255

Same logic applies to 64 bits, which is size_t
*/
void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*s;

	if (elsize != 0 && nelem > (size_t)-1 / elsize)
		return (NULL);
	s = malloc(nelem * elsize);
	if (!s)
		return (NULL);
	ft_bzero(s, nelem * elsize);
	return (s);
}
