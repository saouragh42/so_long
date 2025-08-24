/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:49:54 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 02:29:54 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		map_error(game, "Failed to allocate memory for game structure.");
	parsing_and_validation(game, argv[1]);
	graphics_and_rendering(game);
	mlx_expose_hook(game->window, render_map, game);
	mlx_hook(game->window, KEY_PRESS, KEY_PRESS_MASK, handle_keypress, game);
	mlx_hook(game->window, ON_DESTROY, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
