/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:47:10 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/23 21:31:01 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	graphics_and_rendering(t_game *game);
void	graphics_initialization(t_game *game);
void	*load_texture(t_game *game, char *file_path);

void	graphics_and_rendering(t_game *game)
{
	graphics_initialization(game);
	game->floor = load_texture(game, "textures/floor.xpm");
	game->collectible = load_texture(game, "textures/collectible_blork.xpm");
	game->player.image = load_texture(game, "textures/petit_barbare.xpm");
	game->wall = load_texture(game, "textures/wall.xpm");
	game->exit = load_texture(game, "textures/exit.xpm");
	render_map(game);
}

void	graphics_initialization(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		map_error(game, "Failed to initialize MLX.");
	game->window = mlx_new_window(
			game->mlx,
			game->map.columns * 64,
			game->map.rows * 64,
			"SO_LONG_42 x GAME OVER");
	if (!game->window)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		map_error(game, "Failed to create window.");
	}
}

void	*load_texture(t_game *game, char *file_path)
{
	void	*image;

	image = mlx_xpm_file_to_image(
			game->mlx,
			file_path,
			&(int){64},
			&(int){64});
	if (!image)
		map_error(game, "Failed to load texture.");
	return (image);
}
