/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:50:24 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/01 14:14:29 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_orientation(char c, t_player *player)
{
	if(c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
}

int	player_position(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_delimiter(map[i][j], PLAYER_P))
			{
				player->p_x = j;
				player->p_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	player_orientation(t_player *player, char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_delimiter(map[i][j], PLAYER_P))
			{
				get_orientation(map[i][j], player);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}