/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:47:37 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/16 17:36:24 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *error_msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}

int	is_file_exists(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_line_length(char *line, int expected_len)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len == expected_len);
}

int	is_map_rectangular(char *map_path)
{
	int		fd;
	char	*line;
	int		first_len;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	first_len = ft_strlen(line);
	if (first_len > 0 && line[first_len - 1] == '\n')
		first_len--;
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!check_line_length(line, first_len))
			return (free(line), close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

int	is_map_empty(char *map_path)
{
	int		fd;
	char	*line;
	int		is_empty;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	is_empty = 1;
	if (line)
	{
		if (ft_strlen(line) > 1 || (ft_strlen(line) == 1 && line[0] != '\n'))
			is_empty = 0;
		free(line);
		if (!is_empty)
		{
			line = get_next_line(fd);
			while (line != NULL)
			{
				free(line);
				line = get_next_line(fd);
			}
		}
	}
	return (close(fd), is_empty);
}

/**
 * Checks if the map name is valid.
 * A valid map name must:
 * * - End with ".ber" and not contain any other extensions
 * * - Contain only printable characters
 * "..ber" is not valid
 */
int	is_valid_map_name(char *map_name)
{
	int	len;
	int	i;

	if (!map_name)
		return (0);
	len = ft_strlen(map_name);
	if (len < 5)
		return (0);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
		return (0);
	if (map_name[len - 4] != '.')
		return (0);
	i = 0;
	while (i < len - 4)
	{
		if (!ft_isprint(map_name[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_map_parsing(char *map_path)
{
	if (!is_valid_map_name(map_path))
		map_error("Invalid map name");
	if (!is_file_exists(map_path))
		map_error("Map file does not exist");
	if (is_map_empty(map_path))
		map_error("Map is empty");
	if (!is_map_rectangular(map_path))
		map_error("Map is not rectangular");
}
