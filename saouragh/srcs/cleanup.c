/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:38:14 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 02:15:24 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		cleanup_graphics(t_game *game);
static void	cleanup_window_and_display(t_game *game);
static void	cleanup_images(t_game *game);
int			close_window(t_game *game);

int	close_window(t_game *game)
{
	cleanup_graphics(game);
	free_game(game);
	exit(0);
	return (0);
}

void	cleanup_graphics(t_game *game)
{
	cleanup_images(game);
	cleanup_window_and_display(game);
}

static void	cleanup_window_and_display(t_game *game)
{
	if (game->mlx && game->window)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

static void	cleanup_images(t_game *game)
{
	if (game->mlx && game->player.image)
	{
		mlx_destroy_image(game->mlx, game->player.image);
		game->player.image = NULL;
	}
	if (game->mlx && game->collectible)
	{
		mlx_destroy_image(game->mlx, game->collectible);
		game->collectible = NULL;
	}
	if (game->mlx && game->floor)
	{
		mlx_destroy_image(game->mlx, game->floor);
		game->floor = NULL;
	}
	if (game->mlx && game->wall)
	{
		mlx_destroy_image(game->mlx, game->wall);
		game->wall = NULL;
	}
	if (game->mlx && game->exit)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = NULL;
	}
}
