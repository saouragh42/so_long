/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:17:22 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 21:47:39 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	copy_map(t_game *game);
void	parsing_and_validation(t_game *game, char *map_path);

/**
 * Parses and validates the game map.
 */
void	parsing_and_validation(t_game *game, char *map_path)
{
	init_game_structures(game);
	fill_map_from_file(game, map_path);
	validate_map(game);
}

/**
 * Copy the map into map_copy for pathfinding
*/
void	copy_map(t_game *game)
{
	int	i;

	game->map_copy.rows = game->map.rows;
	game->map_copy.columns = game->map.columns;
	game->map_copy.map_grid = ft_calloc(
			game->map_copy.rows + 1,
			sizeof(char *));
	if (!game->map_copy.map_grid)
		map_error(game, "Failed to allocate memory for map copy");
	i = 0;
	while (i < game->map_copy.rows)
	{
		game->map_copy.map_grid[i] = ft_strdup(game->map.map_grid[i]);
		if (!game->map_copy.map_grid[i])
			map_error(game, "Failed to copy map grid");
		i++;
	}
	game->map_copy.map_grid[i] = NULL;
}
