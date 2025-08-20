/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:35:04 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/20 22:55:19 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		fill_map_from_file(t_map **map, const char *map_path);
static int	count_map_rows(const char *map_path);
static void	load_map(t_map **map, const char *map_path);
static void	set_map_rows_and_cols(t_map **map);

void	fill_map_from_file(t_map **map, const char *map_path)
{
	(*map)->rows = count_map_rows(map_path);
	if ((*map)->rows <= 0)
		map_error("Map is empty");
	(*map)->map = ft_calloc((*map)->rows + 1, sizeof(char *));
	if (!(*map)->map)
		map_error("Failed to allocate memory for map");
	load_map(map, map_path);
	set_map_rows_and_cols(map);
}

/**
 * Counts the number of rows in the map file.
 */
static int	count_map_rows(const char *map_path)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		map_error("Failed to open map file");
	rows = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

static void	load_map(t_map **map, const char *map_path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		map_error("Failed to open map file");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*map)->map[i++] = line;
		line = get_next_line(fd);
	}
	(*map)->map[i] = NULL;
	close(fd);
}

static void	set_map_rows_and_cols(t_map **map)
{
	int	len;

	if ((*map)->rows > 0 && (*map)->map[0])
	{
		len = ft_strlen((*map)->map[0]);
		if (len > 0 && (*map)->map[0][len - 1] == '\n')
			len--;
		(*map)->cols = len;
	}
}
