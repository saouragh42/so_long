/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:38:04 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 21:45:59 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void			check_path_validity(t_game *game);
static void		flood_fill(t_game *game, int row, int col);
static void		flood_fill_path_finding(t_game *game);
static bool		is_walkable(t_game *game, int row, int col);
static void		can_collect_and_escape(t_game *game);

static bool	is_walkable(t_game *game, int row, int col)
{
	if (row < 0 || row >= game->map_copy.rows)
		return (false);
	if (col < 0 || col >= game->map_copy.columns)
		return (false);
	if (game->map_copy.map_grid[row][col] == WALL
		|| game->map_copy.map_grid[row][col] == FILLER)
		return (false);
	return (true);
}

static void	flood_fill(t_game *game, int row, int col)
{
	if (!is_walkable(game, row, col))
		return ;
	if (game->map_copy.map_grid[row][col] == COLLECTIBLE)
		game->map_copy.collectible_count++;
	if (game->map_copy.map_grid[row][col] == EXIT)
		game->map_copy.exit_count++;
	game->map_copy.map_grid[row][col] = FILLER;
	flood_fill(game, row + 1, col);
	flood_fill(game, row - 1, col);
	flood_fill(game, row, col + 1);
	flood_fill(game, row, col - 1);
}

static void	flood_fill_path_finding(t_game *game)
{
	flood_fill(game, game->player.y, game->player.x);
}

static void	can_collect_and_escape(t_game *game)
{
	if (game->map.collectible_count != game->map_copy.collectible_count)
		map_error(game, "Oops! Some treasures are out of bounds!");
	if (game->map.exit_count != game->map_copy.exit_count)
		map_error(game, "GAME OVER: No way out!");
}

void	check_path_validity(t_game *game)
{
	if (!game || !game->map.map_grid)
		return ;
	copy_map(game);
	flood_fill_path_finding(game);
	can_collect_and_escape(game);
}
