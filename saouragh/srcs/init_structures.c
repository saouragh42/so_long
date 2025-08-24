/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:19:43 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 02:41:51 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		init_game_structures(t_game *game);
static void	init_map(t_map *map);
static void	init_player(t_game *game);

void	init_game_structures(t_game *game)
{
	init_map(&game->map);
	init_map(&game->map_copy);
	init_player(game);
	game->mlx = NULL;
	game->window = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->movements = 0;
}

static void	init_map(t_map *map)
{
	map->rows = 0;
	map->columns = 0;
	map->map_grid = NULL;
	map->player_count = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
}

static void	init_player(t_game *game)
{
	game->player.x = -1;
	game->player.y = -1;
	game->player.image = NULL;
	game->player.collectibles = 0;
}
