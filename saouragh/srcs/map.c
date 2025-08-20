/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:47:37 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/20 20:12:35 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_parsing(t_map *map);
bool	is_map_rectangular(t_map *map);
bool	is_map_enclosed_by_walls(t_map *map);

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

bool is_map_rectangular(t_map *map)
{
	int i;
	int len;

	if (!map || map->rows <= 0 || map->cols <= 0)
		map_error("Invalid map structure");
	i = 0;
	while (i < map->rows)
	{
		len = ft_strlen(map->map[i]);
		if (len > 0 && map->map[i][len - 1] == '\n')
			len--;
		if (len != map->cols)
			return (false);
		i++;
	}
	return (true);
}

// bool	is_map_empty(char *map_path)
// {
// 	int		fd;
// 	char	*line;
// 	bool	is_empty;

// 	fd = open(map_path, O_RDONLY);
// 	if (fd < 0)
// 		return (true);
// 	line = get_next_line(fd);
// 	is_empty = true;
// 	if (line)
// 	{
// 		if (ft_strlen(line) > 1 || (ft_strlen(line) == 1 && line[0] != '\n'))
// 			is_empty = false;
// 		free(line);
// 		if (!is_empty)
// 		{
// 			line = get_next_line(fd);
// 			while (line != NULL)
// 			{
// 				free(line);
// 				line = get_next_line(fd);
// 			}
// 		}
// 	}
// 	return (close(fd), is_empty);
// }

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

bool is_map_enclosed_by_walls(t_map *map)
{
	int	r;
	int	c;

	if (!map || map->rows <= 0 || map->cols <= 0)
		return (false);
	r = 0;
	c = 0;
	while (c < map->cols)
	{
		if (map->map[0][c] != WALL || map->map[map->rows - 1][c] != WALL)
			return (false);
		c++;
	}
	while (r < map->rows)
	{
		if (map->map[r][0] != WALL || map->map[r][map->cols - 1] != WALL)
			return (false);
		r++;
	}
	return (true);
}

void	check_map_parsing(t_map *map)
{
	if (!is_map_rectangular(map))
		map_error("Map is not rectangular");
	if (!is_map_enclosed_by_walls(map))
		map_error("Map is not enclosed by walls");
}
