/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:50:24 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/23 14:55:25 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_w_or_e(char c, t_player *player)
{
	if (c == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
	else if (c == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
}

void	get_orientation(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
	else if (c == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else
		get_w_or_e(c, player);
}

int	player_position(t_player *player, char **map)
{
	int	i;
	int	j;
	int	number_player;

	i = 0;
	number_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_delimiter(map[i][j], PLAYER_P))
			{
				player->p_x = (double)j + 0.2;
				player->p_y = (double)i + 0.2;
				number_player++;
			}
			j++;
		}
		i++;
	}
	if (number_player == 1)
		return (1);
	else
		return (0);
}

int	player_orientation(t_player *player, char **map)
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
				get_orientation(map[i][j], player);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
