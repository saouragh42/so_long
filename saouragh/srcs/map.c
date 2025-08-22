/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:47:37 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 15:42:35 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_map(t_game *game);
bool	is_map_rectangular(t_game *game);
bool	is_map_enclosed_by_walls(t_map *map);
void	validate_and_count_map_elements(t_game *game);

void	validate_map(t_game *game)
{
	if (!is_map_rectangular(game))
		map_error(game, "Map is not rectangular");
	if (!is_map_enclosed_by_walls(&game->map))
		map_error(game, "Map is not enclosed by walls");
	validate_and_count_map_elements(game);
}

// int	check_line_length(char *line, int expected_len)
// {
// 	int	len;

// 	len = ft_strlen(line);
// 	if (len > 0 && line[len - 1] == '\n')
// 		len--;
// 	return (len == expected_len);
// }

bool	is_map_rectangular(t_game *game)
{
	t_map	*map;
	int		i;
	int		len;

	map = &game->map;
	if (!map || map->rows <= 0 || map->columns <= 0)
		map_error(game, "Invalid map structure");
	i = 0;
	while (i < map->rows)
	{
		len = ft_strlen(map->map_grid[i]);
		if (len > 0 && map->map_grid[i][len - 1] == '\n')
			len--;
		if (len != map->columns)
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



bool	is_map_enclosed_by_walls(t_map *map)
{
	int	r;
	int	c;

	if (!map || map->rows <= 0 || map->columns <= 0)
		return (false);
	r = 0;
	c = 0;
	while (c < map->columns)
	{
		if (map->map_grid[0][c] != WALL
			|| map->map_grid[map->rows - 1][c] != WALL)
			return (false);
		c++;
	}
	while (r < map->rows)
	{
		if (map->map_grid[r][0] != WALL
			|| map->map_grid[r][map->columns - 1] != WALL)
			return (false);
		r++;
	}
	return (true);
}

static void	check_map_element(t_game *game, int row, int col)
{
	char	element;

	element = game->map.map_grid[row][col];
	if (element == PLAYER)
	{
		game->map.player_count++;
		game->player.x = col;
		game->player.y = row;
	}
	else if (element == EXIT)
		game->map.exit_count++;
	else if (element == COLLECTIBLE)
		game->map.collectible_count++;
	else if (element != WALL && element != EMPTY_SPACE)
		map_error(game, "Invalid character in map");
}

void	validate_and_count_map_elements(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map.map_grid[row])
	{
		col = 0;
		while (game->map.map_grid[row][col])
		{
			check_map_element(game, row, col);
			col++;
		}
		row++;
	}
	if (game->map.player_count != 1)
		map_error(game, "You need exactly one hero! Not a crowd, not a ghost.");
	if (game->map.exit_count != 1)
		map_error(game, "There must be exactly one exit!\
		 Too many exits and he gets lost, too few and he's stuck!");
	if (game->map.collectible_count < 1)
		map_error(game, "No treasures?\
			Adventurers need at least one collectible!");
}

