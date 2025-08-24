/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:56:50 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 01:38:39 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		close_window(game);
	else if (keycode == K_W || keycode == K_Z || keycode == K_AR_UP)
		update_player_position(game, game->player.x, game->player.y - 1);
	else if (keycode == K_A || keycode == K_Q || keycode == K_AR_LEFT)
		update_player_position(game, game->player.x - 1, game->player.y);
	else if (keycode == K_S || keycode == K_AR_DOWN)
		update_player_position(game, game->player.x, game->player.y + 1);
	else if (keycode == K_D || keycode == K_AR_RIGHT)
		update_player_position(game, game->player.x + 1, game->player.y);
	render_map(game);
	return (0);
}
