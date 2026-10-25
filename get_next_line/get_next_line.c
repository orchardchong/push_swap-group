/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlim <junlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:42:44 by junlim            #+#    #+#             */
/*   Updated: 2026/10/23 21:40:24 by junlim           ###   ########.fr       */
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

/*
free(stash) and set it to null to avoid repeated gnl() calls
to free the stash when it comes from piping. Example: sa\nbad\nra\n
This allows us to just free and assign stash a single time when
input is wrong.
*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*processed_line;

	processed_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
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