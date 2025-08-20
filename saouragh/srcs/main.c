/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:49:54 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/20 22:49:56 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->map)
		return ;
	i = 0;
	while (i < map->rows)
		free(map->map[i++]);
	free(map->map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 1)
		map_error("Please provide a map\n./so_long <your map>.ber");
	else if (argc > 2)
		map_error("Too many arguments.");
	if (argc == 2)
	{
		if (!is_valid_map_name(argv[1]))
			map_error("Invalid map name.");
		if (!is_file_exists(argv[1]))
			map_error("Map file does not exist.");
		map = ft_calloc(1, sizeof(t_map));
		init_struct(&map);
		fill_map_from_file(&map, argv[1]);
		check_map_parsing(map);
		free_map(map);
		free(map);
	}
	return (0);
}
