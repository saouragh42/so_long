/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:48:53 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 02:49:03 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	if (n == 0)
		return ;
	while (n--)
		*p++ = 0;
}

char	*obtain_remaining(char *static_buffer)
{
	char	*newline;
	char	*remaining;

	newline = ft_strchr(static_buffer, '\n');
	if (!newline)
	{
		free(static_buffer);
		return (NULL);
	}
	remaining = ft_strdup_gnl(newline + 1);
	free(static_buffer);
	return (remaining);
}

char	*extract_line(char	*static_buffer)
{
	int		i;
	char	*line;
	int		size;

	size = ft_strlen_until(static_buffer, '\n');
	if (static_buffer[0] != '\n' && size == 0)
		return (NULL);
	line = ft_calloc_gnl(size + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_from_file(int fd, char *static_buffer)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(static_buffer);
			return (free(read_buffer), NULL);
		}
		read_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin_free(static_buffer, read_buffer, bytes_read);
		if (ft_strchr(static_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!static_buffer)
		static_buffer = ft_calloc_gnl(1, sizeof(char));
	if (!static_buffer)
		return (NULL);
	if (!ft_strchr(static_buffer, '\n'))
		static_buffer = read_from_file(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = extract_line(static_buffer);
	static_buffer = obtain_remaining(static_buffer);
	return (line);
}
