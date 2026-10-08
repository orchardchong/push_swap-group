/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:31:38 by junlim            #+#    #+#             */
/*   Updated: 2026/08/25 18:33:28 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Note, however, that if strlcat() traverses size characters without finding a 
NUL, the length of the string is considered to be size and the destination 
string will not be NUL-terminated (since there was no space for the NUL)

--> this means when dst's length is bigger than its buffer size, so just return
the supposed concat string of dstsize + src, and don't do anything to avoid
unsafe concat. Because we should only concat when there is enough spaces in dst,
which mean dstsize should be greater than dst's current length.

dstsize > dst_len + 1 is to calculate the remaining space
*/
/*
if dstsize is -negative, it will become a very large number and get caught
by if (dst_len > dstsize)
*/
/*
Further improvement

	Don't use ft_strlen(dst) here. Use a bounded search equivalent to 
	strnlen(dst, dstsize). This never reads beyond the first dstsize 
	bytes. If dst's length > buffer size (dstsize), means no space and return.

	 * 
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == dstsize)
		return (dstsize + src_len);

	// Example 1:
	//   dst     = "Hello"
	//   dstsize = 3
	//
	// The actual string length is 5, but we only search the first 3 bytes.
	// Therefore dst_len becomes 3 (not 5), and we return without appending.
	
	// Example 2:
	//   char dst[5] = {'H', 'e', 'l', 'l', 'o'};
	//   dstsize = 5
	//
	// ft_strlen(dst) would continue reading past the end of dst looking for
	// '\0', causing undefined behavior. The bounded search stops after the
	// first 5 bytes, so it never reads outside the destination buffer.
*/
#include "libft.h"
#include <stdio.h>

/*
1.
-fsanitize=address if not applied when creating libft.a, then this check
will not applied to ft_strlen.

yining's previous solution did:
while(dst[i])
	i++;
in ft_strlcat, which is instrumented  with this flag, and will catch
buffer overflow.

2.
Root cause: -fsanitize=address is a compile-time instrumentation flag,
applied per translation unit at the moment clang compiles a .c file.
It does NOT apply to already-compiled .o files sitting inside a 
prebuilt libft.a. 
If we want to apply this flag to the library's function, we should do it in 
compile time.

3.
fix is to bound the scan by `size` directly inside ft_strlcat
to prevent overflow at the first place:

    i = 0;
    while (i < size && dst[i])
        i++;
    dst_len = i;

4.
To verify a fix (or confirm a suspected bug) with full ASan coverage,
temporarily rebuild libft.a itself with -fsanitize=address in CFLAGS,
`make fclean && make`, then relink. Revert CFLAGS before final
submission — ASan isn't part of the expected deliverable.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (dstsize + src_len);
	while (src[i] && dstsize > dst_len + i + 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char dest_ft[10] = "Hello";
	char *src_ft = " World";
	char dest[10] = "Hello";
	char *src = " World";

	//change 10 -> 5 to check if (dst_len > dstsize)
	printf("dest_ft's length: %ld\n", ft_strlcat(dest_ft, src_ft, 10));
	printf("dest_ft: %s\n", dest_ft);
	printf("dest's length: %ld\n", strlcat(dest, src, 10));
	printf("dest: %s\n", dest);
}
*/
