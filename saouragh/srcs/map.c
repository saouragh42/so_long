/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:47:37 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/11 18:12:20 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *error_msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
}

int	is_valid_map_name(char *map_name)
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
	i = 0;
	while (i < len - 4)
	{
		if (!ft_isprint(map_name[i]) || map_name[i] == ' '
			|| map_name[i] == '.' || map_name[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}
