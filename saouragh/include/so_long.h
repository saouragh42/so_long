/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:50:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 02:20:49 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>

// --- Map Characters ---
# define EMPTY_SPACE      '0'
# define WALL            '1'
# define COLLECTIBLE     'C'
# define EXIT            'E'
# define PLAYER          'P'
# define FILLER          'F'
# define PLAYER_ON_EXIT  'X'

// --- MLX/X11 Event Codes ---
# define ON_DESTROY      17
# define KEY_PRESS       2
# define KEY_PRESS_MASK  (1L<<0)

// --- Key Codes ---
# define K_AR_LEFT   65361
# define K_AR_UP     65362
# define K_AR_RIGHT  65363
# define K_AR_DOWN   65364
# define K_A         97
# define K_D         100
# define K_Q         113
# define K_S         115
# define K_W         119
# define K_Z         122
# define K_ESC       65307

typedef struct s_player
{
	int		x;
	int		y;
	void	*image;
	int		collectibles;
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
	void			*mlx;
	void			*window;
	void			*floor;
	void			*wall;
	void			*collectible;
	void			*exit;
	int				movements;
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

// --- Graphics & Rendering ---
void	graphics_and_rendering(t_game *game);
int		render_map(t_game *game);
void	draw_collectible(t_game *game, int col, int row);
void	draw_player(t_game *game, int col, int row);
void	draw_exit(t_game *game, int col, int row);
void	draw_wall(t_game *game, int col, int row);
void	draw_player_on_exit(t_game *game, int col, int row);

// --- Game Logic ---
void	update_player_position(t_game *game, int x, int y);
bool	is_walkable(t_map map, int row, int col);
int		handle_keypress(int keycode, t_game *game);

// --- Cleanup & Error Handling ---
int		close_window(t_game *game);
void	cleanup_graphics(t_game *game);
void	map_error(t_game *game, char *message);
void	free_map(t_map *map);
void	free_game(t_game *game);

#endif