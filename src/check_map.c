/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:14:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/20 15:22:54 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color(t_data *data)
{
	print_info(data->color);
}

int	check_walls(char **map)
{
	if (!check_first_rc(map))
		return (0);
	if (!check_last_row(map))
		return (0);
	if (!check_last_col(map))
		return (0);
	if (!check_spaces(map))
		return (0);
	return (1);
}

int	check_wrong_input(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!check_delimiter(map[i][j], MAPCODES))
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(char **map)
{
	if (map == NULL)
		error_msg("Empty map");
	if (!check_walls(map))
		error_msg("Map is not surrounded by walls");
	if (!check_wrong_input(map))
		error_msg("Invalid char in the map");
}
