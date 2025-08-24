/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:35:04 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/23 14:55:20 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		fill_map_from_file(t_game *game, const char *map_path);
static int	count_map_rows(const char *map_path);
static void	load_map(t_game *game, const char *map_path);

/**
 * Fills the game map from the specified file.
 */
void	fill_map_from_file(t_game *game, const char *map_path)
{
	game->map.rows = count_map_rows(map_path);
	if (game->map.rows <= 0)
		map_error(game, "Map is empty");
	game->map.map_grid = ft_calloc(game->map.rows + 1, sizeof(char *));
	if (!game->map.map_grid)
		map_error(game, "Failed to allocate memory for map");
	load_map(game, map_path);
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
		map_error(NULL, "Failed to open map file");
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

/**
 * Loads the map data from the specified file into the game structure.
 * Sets the number of rows and columns.
 */
static void	load_map(t_game *game, const char *map_path)
{
	int		fd;
	int		i;
	char	*line;
	int		len;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		map_error(game, "Failed to open map file");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map.map_grid[i++] = line;
		line = get_next_line(fd);
	}
	game->map.map_grid[i] = NULL;
	if (game->map.rows > 0 && game->map.map_grid[0])
		game->map.columns = ft_strlen(game->map.map_grid[0]);
	close(fd);
}
