/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:50:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/16 17:36:23 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>

// Function declarations
void	map_error(char *message);
int		is_valid_map_name(char *map_name);
int		is_map_empty(char *map_path);
int		check_line_length(char *line, int expected_len);
void	check_map_parsing(char *map_path);

#endif