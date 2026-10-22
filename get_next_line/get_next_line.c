/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:42:44 by junlim            #+#    #+#             */
/*   Updated: 2026/10/22 16:21:43 by junlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	append_to_stash(char **stash, char *buffer)
{
	char	*joined_str;

	joined_str = ft_strjoin(*stash, buffer);
	if (!joined_str)
		return (0);
	free(*stash);
	*stash = joined_str;
	return (1);
}

int	get_newline_index(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
/*
1. have to free stash because each ft_strjoin will allocate new heap memory.
2. have to assign '\0' because read doesnt gurantee that. Without this and 
getting near EOF, when bytes read < BUFFER_SIZE, it will overwrite the first
n bytes, and the chars from previous buffer is still there.
*/
/*
If the program is run with valgrind and file that has very long string, it 
will be slower due to ft_strlen(), which reads from the memory too frequently 
for BUFFER_SIZE=1.

Example when BUFFER_SIZE=1,:

** Cost of one ft_strjoin(stash, buffer), stash length k, BUFFER_SIZE = 1
**
** | Call                              | String                | Work |
** |-----------------------------------|-----------------------|------|
** | ft_strlen(s1) in ft_strjoin       | stash                 | k    |
** | ft_strlen(s2) in ft_strjoin       | buffer                | 1    |
** | strlcat #1: ft_strlen(dst)        | empty concat_s        | 0    |
** | strlcat #1: ft_strlen(src)        | stash                 | k    |
** | strlcat #2: ft_strlen(dst)        | concat_s (stash copy) | k    |
** | strlcat #2: ft_strlen(src)        | buffer                | 1    |
** Total: 3k + 2 steps

** Cost of one ft_strjoin(stash, buffer), stash length k, BUFFER_SIZE = 4
**
** | Call                              | String                | Work |
** |-----------------------------------|-----------------------|------|
** | ft_strlen(s1) in ft_strjoin       | stash                 | k    |
** | ft_strlen(s2) in ft_strjoin       | buffer                | 4    |
** | strlcat #1: ft_strlen(dst)        | empty concat_s        | 0    |
** | strlcat #1: ft_strlen(src)        | stash                 | k    |
** | strlcat #2: ft_strlen(dst)        | concat_s (stash copy) | k    |
** | strlcat #2: ft_strlen(src)        | buffer                | 4    |
** Total: 3k + 8 steps

Say we have a file: "01234.........9999"
** Line "0123", BUFFER_SIZE = 1, buffer length b (b = 1 in this case)
** strlen steps per join = 3k + 2b, copy steps per join = k + b
**
** | Join # | k (stash) | strlen steps (3k + 2) | copy steps (k + 1) |
** |--------|-----------|-----------------------|--------------------|
** | 1      | 0         | 2                     | 1                  |
** | 2      | 1         | 5                     | 2                  |
** | 3      | 2         | 8                     | 3                  |
** | 4      | 3         | 11                    | 4                  |
** | Total  |           | 26                    | 10                 |
**
** total = 26 + 10 = 36

** Line "0123", BUFFER_SIZE = 4 (b = 4), all steps counted
** strlen steps per join = 3k + 2b, copy steps per join = k + b
**
** | Join # | k (stash) | strlen steps (3k + 8) | copy steps (k + 4) |
** |--------|-----------|-----------------------|--------------------|
** | 1      | 0         | 8                     | 4                  |
** | Total  |           | 8                     | 4                  |
**
** total = 8 + 4 = 12

36 > 12
Therefore, when BUFFER_SIZE=1, there would be more memory reads, as ft_strlen()
uses while(s[i]). Combined with valgrind, it wraps these memory access with extra
checks, which slows down the programs, so the tester's timeout needs to change.

time valgrind -q --leak-check=full ./a.out to verify
*/
/*
if (get_newline_index(*stash) >= 0)
not > 0, because newline can starts at position 0, reduce extra calls, especially
with when BUFFER_SIZE=1
*/

int	read_file(int fd, char **stash)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (bytes_read > 0 && get_newline_index(*stash) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read >= 0)
		{
			buffer[bytes_read] = '\0';
			if (append_to_stash(stash, buffer) == 0)
				bytes_read = -1;
		}
	}
	free (buffer);
	if (bytes_read < 0)
		return (-1);
	return (1);
}

/*
1. ft_substr and ft_strjoin can return empty strings
2. edge cases:
	1. when file is empty
	2. when there is no newline 
*/

// is this necessary? while (read(fd, buffer, BUFFER_SIZE) > 0)
// should prevent stash being ""
/*
if stash is "", should also freed it.

remaining_stash is local, no need = NULL. but get_next_line have
to return NULL when malloc fails. By returning early, this keeps the
stash untouch
*/
void	get_str_newline_and_remaining_stash(char **stash, char **line)
{
	char	*remaining_stash;
	int		new_line_index;

	if (**stash == '\0')
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	new_line_index = get_newline_index(*stash);
	if (new_line_index == -1)
		new_line_index = ft_strlen(*stash) - 1;
	*line = ft_substr(*stash, 0, new_line_index + 1);
	remaining_stash = ft_substr(*stash, new_line_index + 1, ft_strlen(*stash));
	if (!*line || !remaining_stash)
	{
		free(*line);
		free(remaining_stash);
		*line = NULL;
		return ;
	}
	free(*stash);
	*stash = remaining_stash;
}

/*assign stash to "" for the first call as ft_strlen() doesnt handle NULL*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*processed_line;

	processed_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (read_file(fd, &stash) < 0)
		return (NULL);
	get_str_newline_and_remaining_stash(&stash, &processed_line);
	return (processed_line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int fd = open("nl", O_RDONLY);
// 	char *str;

// 	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// // 	str = get_next_line(fd);
// // 	printf("%s", str);
// // 	free(str);
// // 	str = get_next_line(fd);
// // 	printf("%s", str);
// // 	free(str);
// }