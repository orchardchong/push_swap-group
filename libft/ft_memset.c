/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:37:05 by junlim            #+#    #+#             */
/*   Updated: 2026/08/25 18:25:36 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
       The memset() function fills the first n bytes of the memory area
       pointed to by s with the constant byte c.
RETURN VALUE
       The memset() function returns a pointer to the memory area s.
c is expected to be 
*/

//cast to char* to do pointers arithmetic, if not compiler doesn't know
// how many bytes to move
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		*(str + i++) = c;
	return (s);
}
/* libft tester warmachine

Compiled with -fsanitize=address. Under WSL, LeakSanitizer's exit-time
heap scan can hang when the test's main() leaves an unfree'd malloc 
— LSan's thread-suspend step seems to stall on WSL's ptrace layer specifically.

Workaround for local testing only:
  ASAN_OPTIONS=detect_leaks=0 ./user_exe
This disables just the leak scan, keeps full ASan error detection.
Not seen on native Linux / actual grading environment.

int		main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	alarm(5);
	if (!(mem = malloc(sizeof(*mem) * 15)) || argc == 1)
		return (0);
	memset(mem, 'j', 15);
}
*/
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[32] = "This is to learn about memset()"; // +1 for null
	ft_memset(str + 15, '*', 5);
	printf("ft_memset: %s\n",str);
	memset(str + 15 , '*', 5);
	printf("memset: %s\n",str);
	return (0);
}

it works when c = 0 or c = -1 as the output will be the same in
1 byte or 4 byte conditions
in this case if 40 bytes all 0x02:
		0x02 0x02 0x02 0x02 0x02 .... 
n byte:  1    2    3    4    5
then the first array element, which is int that has 4 bytes,
would be interpreted as 0x02020202 which is 33686018

void printArray(int arr[], int n)
{
   for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
}

int main()
{
    int n = 10;
    int arr[n];

    // Fill whole array with 100.
    memset(arr, 2, n*sizeof(arr[0]));
    printf("Array after memset()\n");
    printArray(arr, n);

    return 0;
}
*/