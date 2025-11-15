/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:43:47 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/30 16:18:38 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(int fd, char *buffer, char *remaining);
char	*divide_line_and_save_rest(char *line);

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		free(buffer);
		remaining = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_line(fd, buffer, remaining);
	if (!line)
	{
		free(buffer);
		free(remaining);
		remaining = NULL;
		return (NULL);
	}
	remaining = divide_line_and_save_rest(line);
	free(buffer);
	return (line);
}

char	*read_line(int fd, char *buffer, char *remaining)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else if (bytes_read == 0)
			return (remaining);
		buffer[bytes_read] = '\0';
		temp = remaining;
		remaining = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(remaining, '\n'))
			return (remaining);
	}
	return (remaining);
}

char	*divide_line_and_save_rest(char *line)
{
	int		i;
	char	*save_rest;

	i = 0;
	if (line[i] == '\0')
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (!line[i])
		return (NULL);
	save_rest = ft_substr(line, i, (ft_strlen(line) - i));
	if (!save_rest)
		return (NULL);
	line[i] = '\0';
	return (save_rest);
}
