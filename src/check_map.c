/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:14:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/20 16:47:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	check_first_rc(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = get_map_height(map);
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' && map[0][i] != ' ')
			return (0);
		i++;
	}
	return (1);
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
