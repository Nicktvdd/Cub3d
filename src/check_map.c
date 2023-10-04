/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:14:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/04 18:03:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls(char **map)
{
	if (!check_firts_rc(map))
		return (0);
	if (!check_last_row(map))
		return (0);
	if (!check_last_col(map))
		return (0);
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
			if (map[i][j] == 'N' || map[i][j] == '1'
				|| map[i][j] == '0' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'W')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void check_map(char **map)
{
	if (map == NULL)
		error_msg("Empty map");
	if (!check_walls(map))
		error_msg("Map is not surrounded by walls");
	if (!check_wrong_input(map))
		error_msg("Invalid char in the map");
}
