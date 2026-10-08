/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:28:03 by junlim            #+#    #+#             */
/*   Updated: 2026/08/15 20:55:24 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *s, char delim)
{
	int	inword;
	int	count;

	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s == delim)
			inword = 0;
		else if (!inword)
		{
			count++;
			inword = 1;
		}
		s++;
	}
	return (count);
}

static int	add_split_words(char **str_array, const char *s, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	i_words;
	char			*sub_str;

	i = 0;
	i_words = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			sub_str = ft_substr(s, start, i - start);
			if (!sub_str)
				return (0);
			str_array[i_words++] = sub_str;
		}
		else
			i++;
	}
	return (1);
}

static void	free_split_str(char **str_array)
{
	unsigned int	i;

	i = 0;
	while (str_array[i])
		free(str_array[i++]);
	free(str_array);
}
/*
FINDINGS
1.
when an array of strings is returned, add null string at the end:
1. knows when to stop when no size is returned
2. when s is empty, that array is correctly initialized

2.
ft_calloc() is called 1 time so if allocation failed return NULL
ft_substr() might be called more than 1 times, and it might fail
during the process. 

say if allocation fails at the 3rd string, there would be 2 allocated
space but null is returned. The requirements stated to return NULL
when allocation fails, losing the address of split_str and cannot free
those spaces outside ft_split().

so have to free it before returning NULL.

3.
split_str[i_words] = "\0"; this is a string that contains null, not
empty string

4.
split_str[i_words] = 0; this is not necessary when i use calloc, which
correctly inizialize all the memory spaces with '\0'

5.
when s, calloc returns empty string
*/

char	**ft_split(char const *s, char c)
{
	char			**split_str;
	int				success;

	success = 0;
	split_str = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!split_str)
		return (0);
	success = add_split_words(split_str, s, c);
	if (!success)
	{
		free_split_str(split_str);
		return (0);
	}
	return (split_str);
}

/*
#include <stdio.h>  
#include <string.h>

void	check(const char *desc, char **result, const char **expected,
		int expected_count)
{
	int	i;
	int	ok;

	ok = 1;
	if (!result)
	{
		printf("%-30s -> (NULL)  %s\n", desc,
			expected_count == -1 ? "PASS (NULL expected)" :
			"FAIL (unexpected NULL)");
		return ;
	}
	i = 0;
	while (result[i])
		i++;
	if (i != expected_count)
		ok = 0;
	else
	{
		i = 0;
		while (i < expected_count)
		{
			if (strcmp(result[i], expected[i]) != 0)
				ok = 0;
			i++;
		}
	}
	printf("%-30s -> [", desc);
	i = 0;
	while (result[i])
	{
		printf("\"%s\"%s", result[i], result[i + 1] ? ", " : "");
		i++;
	}
	printf("]  %s\n", ok ? "PASS" : "FAIL");

	// free every string + the array itself
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

int	main(void)
{
	const char	*exp1[] = {"Hello", "World"};
	check("normal split", ft_split("Hello World", ' '), exp1, 2);

	const char	*exp2[] = {"a", "b", "c"};
	check("multiple delimiters", ft_split("a,,b,,,c", ','), exp2, 3);

	const char	*exp3[] = {"Hello"};
	check("leading delimiter", ft_split(",Hello", ','), exp3, 1);

	const char	*exp4[] = {"Hello"};
	check("trailing delimiter", ft_split("Hello,", ','), exp4, 1);

	const char	*exp5[] = {};
	check("empty string", ft_split("", ' '), exp5, 0);

	const char	*exp6[] = {};
	check("string is only delimiters", ft_split(",,,,", ','), exp6, 0);

	const char	*exp7[] = {"Hello World"};
	check("delimiter not present", ft_split("Hello World", ','), exp7, 1);

	const char	*exp8[] = {"a", "b", "c"};
	check("single char tokens", ft_split("a b c", ' '), exp8, 3);

	const char	*exp9[] = {"one"};
	check("single word, no delimiter in string", ft_split("one", ' '), exp9, 1);

	const char	*exp10[] = {"Hello World"};
	check("0 as delim", ft_split("Hello World", 0), exp10, 1);
	return (0);
}
*/
/* HOW TO CHECK MEMORY LEAKS
1. Address sanitizer: -fsanitize=address -g with .c files during compilation. 
Only shows when there is memory leak

	char *g = malloc(10); //add this for simple memory leak mock
	(void)g;
=================================================================
==332717==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 10 byte(s) in 1 object(s) allocated from:
    #0 0x725c518fd9c7 in malloc ../../../../src/libsanitizer/asan/asan_mal...
    #1 0x57d848d6eedc in main /home/junhonglim4979/42kl/core/libft/ft_split.c:179
    #2 0x725c5142a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_...
    #3 0x725c5142a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x57d848d6e224 in _start (/home/junhonglim4979/42kl/core/libft/a.out+...

SUMMARY: AddressSanitizer: 10 byte(s) leaked in 1 allocation(s).

2. VALGRIND: valgrind --leak-check=full ./a.out  after compilation
==330845== 
==330845== HEAP SUMMARY:
==330845==     in use at exit: 0 bytes in 0 blocks
==330845==   total heap usage: 22 allocs, 22 frees, 1,244 bytes allocated
==330845== 
==330845== All heap blocks were freed -- no leaks are possible
==330845== 
==330845== For lists of detected and suppressed errors, rerun with: -s
==330845== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
/*
VERSIONS:
1.
static	int	count_words(char *s, char delim)
{
	int	inword;
	int	count;
	
	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s != delim && inword == 0)
		{	
			count++;
			inword = 1;
			while (*s != delim)
				s++;
		} 
		else
			s++;
			
	}
	return (count);
}

inword flag is redundant when i will use while loop to skip
when i is in a word.  

*/
/*
int	main(void)
{
	char *s = "split this string";
	char delim = ' ';
	char **split;
	int	i;

	i = 0;
	split = ft_split(s, delim);
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i++]);
	}
	free(split);
}
*/
