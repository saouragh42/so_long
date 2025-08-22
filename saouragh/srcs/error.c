/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 02:14:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 14:21:35 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_error(t_game *game, char *error_msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->map_grid)
		return ;
	i = 0;
	while (i < map->rows)
		free(map->map_grid[i++]);
	free(map->map_grid);
}

void	free_game(t_game *game)
{
	free_map(&game->map);
	free_map(&game->map_copy);
	free(game);
}
