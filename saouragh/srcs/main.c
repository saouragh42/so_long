/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:49:54 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/08 14:00:34 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		map_error("Please provide a map\n./so_long <your map>.ber");
	else if (argc > 2)
		map_error("Too many arguments.");
	else if (!is_valid_map_name(argv[1]))
		map_error("Map name is not valid.");
	return (0);
}
