/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:50:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/20 22:30:05 by saouragh         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	// int		player_count;
	// int		exit_count;
	// int		collectible_count;
}	t_map;


// Function declarations
void	map_error(char *message);
int		is_file_exists(char *map_path);
void	init_struct(t_map **map);
void	fill_map_from_file(t_map **map, const char *map_path);

int		is_file_exists(char *map_path);
bool	is_map_rectangular(t_map *map);
int		is_valid_map_name(char *map_name);
bool	is_map_empty(char *map_path);
int		check_line_length(char *line, int expected_len);
void	check_map_parsing(t_map *map);

#endif