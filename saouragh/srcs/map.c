/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:47:37 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/08 13:55:12 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *error_msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
}

//TODO avoid ..ber and a .ber
int	is_valid_map_name(char *map_name)
{
	int	len;

	if (!map_name)
		return (0);
	len = ft_strlen(map_name);
	if (len < 5)
		return (0);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}
