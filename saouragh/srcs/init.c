/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:19:43 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/20 22:29:14 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_struct(t_map **map)
{
	(*map)->map = NULL;
	(*map)->rows = 0;
	(*map)->cols = 0;
	// (*map)->player_count = 0;
	// map->exit_count = 0;
	// map->collectible_count = 0;
}
