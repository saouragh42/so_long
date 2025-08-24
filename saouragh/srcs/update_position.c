/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:24:40 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 01:35:15 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		update_player_position(t_game *game, int x, int y);
static void	update_collectible(t_game *game, int x, int y);
static void	update_exit_win(t_game *game);
static void	update_exit_overlay(t_game *game, int x, int y);
static void	update_normal_move(t_game *game, int x, int y);

/**
 * Updates the player's position on the map based on the intended move.
 * Handles collectible pickup, exit logic (win or overlay), and normal movement.
 * - If the target cell is not walkable, does nothing.
 * - If moving onto a collectible, increments the player's collectible count.
 * - If moving onto the exit with all collectibles, triggers win and closes the 
 * game.
 * - If moving onto the exit without all collectibles, overlays player on exit.
 * - Otherwise, performs a normal move.
 * Also updates the move counter and prints the number of moves after each valid 
 * move.
 */
void	update_player_position(t_game *game, int x, int y)
{
	char	next_position;

	if (!is_walkable(game->map, y, x))
		return ;
	next_position = game->map.map_grid[y][x];
	if (next_position == COLLECTIBLE)
		update_collectible(game, x, y);
	if (next_position == EXIT || next_position == PLAYER_ON_EXIT)
	{
		if (game->player.collectibles == game->map.collectible_count)
		{
			update_exit_win(game);
			return ;
		}
		else
		{
			update_exit_overlay(game, x, y);
			return ;
		}
	}
	update_normal_move(game, x, y);
}

static void	update_collectible(t_game *game, int x, int y)
{
	game->player.collectibles++;
	game->map.map_grid[y][x] = EMPTY_SPACE;
}

static void	update_exit_win(t_game *game)
{
	game->movements++;
	ft_printf(
		"Congratulations! You've won the game in %d moves!\n",
		game->movements);
	close_window(game);
}

static void	update_exit_overlay(t_game *game, int x, int y)
{
	if (game->map.map_grid[game->player.y][game->player.x] == PLAYER_ON_EXIT)
		game->map.map_grid[game->player.y][game->player.x] = EXIT;
	else
		game->map.map_grid[game->player.y][game->player.x] = EMPTY_SPACE;
	game->player.x = x;
	game->player.y = y;
	game->map.map_grid[y][x] = PLAYER_ON_EXIT;
	game->movements++;
	ft_printf("Moves: %d\n", game->movements);
}

static void	update_normal_move(t_game *game, int x, int y)
{
	if (game->map.map_grid[game->player.y][game->player.x] == PLAYER_ON_EXIT)
		game->map.map_grid[game->player.y][game->player.x] = EXIT;
	else
		game->map.map_grid[game->player.y][game->player.x] = EMPTY_SPACE;
	game->player.x = x;
	game->player.y = y;
	game->map.map_grid[y][x] = PLAYER;
	game->movements++;
	ft_printf("Moves: %d\n", game->movements);
}