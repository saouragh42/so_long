/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:21:10 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 01:23:12 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_collectible(t_game *game, int col, int row);
void	draw_player(t_game *game, int col, int row);
void	draw_exit(t_game *game, int col, int row);
void	draw_wall(t_game *game, int col, int row);
void	draw_player_on_exit(t_game *game, int col, int row);

void	draw_collectible(t_game *game, int col, int row)
{
	mlx_put_image_to_window(
		game->mlx, game->window, game->floor, col * 64, row * 64);
	mlx_put_image_to_window(
		game->mlx, game->window, game->collectible, col * 64, row * 64);
}

void	draw_player(t_game *game, int col, int row)
{
	mlx_put_image_to_window(
		game->mlx, game->window, game->floor, col * 64, row * 64);
	mlx_put_image_to_window(
		game->mlx, game->window, game->player.image, col * 64, row * 64);
}

void	draw_exit(t_game *game, int col, int row)
{
	mlx_put_image_to_window(
		game->mlx, game->window, game->floor, col * 64, row * 64);
	mlx_put_image_to_window(
		game->mlx, game->window, game->exit, col * 64, row * 64);
}

void	draw_wall(t_game *game, int col, int row)
{
	mlx_put_image_to_window(
		game->mlx, game->window, game->wall, col * 64, row * 64);
}

void	draw_player_on_exit(t_game *game, int col, int row)
{
	draw_exit(game, col, row);
	mlx_put_image_to_window(
		game->mlx, game->window, game->player.image, col * 64, row * 64);
}
