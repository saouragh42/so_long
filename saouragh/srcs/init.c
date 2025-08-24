/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 02:18:20 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 02:39:29 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void			check_args(int argc, char **argv);
static int		is_file_exists(char *map_path);
static int		is_valid_map_name(char *map_name);

void	check_args(int argc, char **argv)
{
	if (argc < 2)
		map_error(NULL, "Please provide a map\n./so_long <your map>.ber");
	else if (argc > 2)
		map_error(NULL, "Too many arguments.");
	if (!is_valid_map_name(argv[1]))
		map_error(NULL, "Invalid map name.");
	if (!is_file_exists(argv[1]))
		map_error(NULL, "Map file does not exist.");
}

/**
 * Checks if the map name is valid.
 * A valid map name must:
 * * - End with ".ber" and not contain any other extensions
 * * - Contain only printable characters
 * "..ber" is not valid
 */
static int	is_valid_map_name(char *map_name)
{
	int	len;
	int	i;

	if (!map_name)
		return (0);
	len = ft_strlen(map_name);
	if (len < 5)
		return (0);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
		return (0);
	if (map_name[len - 4] != '.')
		return (0);
	i = 0;
	while (i < len - 4)
	{
		if (!ft_isprint(map_name[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_file_exists(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
