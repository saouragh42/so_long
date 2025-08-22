/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:50:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 15:41:34 by saouragh         ###   ########.fr       */
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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**map_grid;
	int		rows;
	int		columns;
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


// Function declarations

void	check_args(int argc, char **argv);
void	init_game_structures(t_game *game);
void	fill_map_from_file(t_game *game, const char *map_path);
void	validate_map(t_game *game);

void	map_error(t_game *game, char *message);
void	free_map(t_map *map);
void	free_game(t_game *game);

int		is_valid_map_name(char *map_name);
int		is_file_exists(char *map_path);

bool	is_map_rectangular(t_game *game);
bool	is_map_empty(char *map_path);
int		check_line_length(char *line, int expected_len);


#endif