/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:57:58 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 01:57:05 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int			render_map(t_game *game);
static void	render_element(t_game *game, int col, int row);

int	render_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.rows)
	{
		col = 0;
		while (col < game->map.columns)
		{
			render_element(game, col, row);
			col++;
		}
		row++;
	}
	return (0);
}

static void	render_element(t_game *game, int col, int row)
{
	if (game->map.map_grid[row][col] == WALL)
		draw_wall(game, col, row);
	else if (game->map.map_grid[row][col] == COLLECTIBLE)
		draw_collectible(game, col, row);
	else if (game->map.map_grid[row][col] == EXIT)
		draw_exit(game, col, row);
	else if (game->map.map_grid[row][col] == PLAYER)
		draw_player(game, col, row);
	else if (game->map.map_grid[row][col] == PLAYER_ON_EXIT)
		draw_player_on_exit(game, col, row);
	else
		mlx_put_image_to_window(
			game->mlx, game->window, game->floor, col * 64, row * 64);
}
