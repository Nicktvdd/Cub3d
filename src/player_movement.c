/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:44:56 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/08 18:06:41 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x + player->dir_y * data->m_speed);
	y = (int)player->p_y;
	if (data->map[x][y] != '1')
		player->p_x += player->dir_y * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y + player->dir_x * data->m_speed);
	if (data->map[x][y] != '1')
		player->p_y += player->dir_x * data->m_speed;
	data->img->instances->x += (int)player->p_x;
}

void	move_left(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x + player->dir_y * data->m_speed);
	y = (int)player->p_y;
	if (data->map[x][y] != '1')
		player->p_x += player->dir_y * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y - player->dir_x * data->m_speed);
	if (data->map[x][y] != '1')
		player->p_y -= player->dir_x * data->m_speed;
	data->img->instances->x -= (int)player->p_x;
	
}

void	move_down(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x - player->dir_x * data->m_speed);
	y = (int)player->p_y;
	if (data->map[x][y] != '1')
		player->p_x -= player->dir_x * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y - player->dir_y * data->m_speed);
	if (data->map[x][y] != '1')
		player->p_y -= player->dir_y * data->m_speed;
	data->img->instances->y += (int)player->p_y;
}

void	move_up(t_data *data, t_player *player)
{
	int	x;
	int	y;
	
	x = (int)(player->p_x + player->dir_x * data->m_speed);
	y = (int)(player->p_y);
	if (data->map[x][y] != '1')
		player->p_x += player->dir_x * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y + player->dir_y * data->m_speed);
	if (data->map[x][y] != '1')
		player->p_y += player->dir_y;
	data->img->instances->y -= (int)player->p_y;
}
