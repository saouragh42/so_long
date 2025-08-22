/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:50:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 21:51:34 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define FILLER 'F'

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	int		rows;
	int		columns;
	char	**map_grid;
	int		player_count;
	int		exit_count;
	int		collectible_count;
}	t_map;

typedef struct s_game
{
	struct s_map	map;
	struct s_map	map_copy;
	struct s_player	player;
}	t_game;


// --- Initialization & Parsing ---
void	check_args(int argc, char **argv);
void	init_game_structures(t_game *game);
void	fill_map_from_file(t_game *game, const char *map_path);
void	parsing_and_validation(t_game *game, char *map_path);

// --- Map Validation & Pathfinding ---
void	validate_map(t_game *game);
void	check_path_validity(t_game *game);
void	copy_map(t_game *game);

// --- Error Handling & Freeing ---
void	map_error(t_game *game, char *message);
void	free_map(t_map *map);
void	free_game(t_game *game);

#endif