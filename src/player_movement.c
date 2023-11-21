/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:44:56 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/21 15:04:21 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x - player->dir_y * data->m_speed);
	y = (int)player->p_y;
	if (data->map[y][x] != '1')
		player->p_x -= player->dir_y * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y + player->dir_x * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y += player->dir_x * data->m_speed;
	// ft_memset(data->img->pixels, 0, data->img->width * data->img->height
	// 	* sizeof(int32_t));
	// render(data);
}

void	move_left(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x + player->dir_y * data->m_speed);
	y = (int)player->p_y;
	if (data->map[y][x] != '1')
		player->p_x += player->dir_y * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y - player->dir_x * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y -= player->dir_x * data->m_speed;
	// ft_memset(data->img->pixels, 0, data->img->width * data->img->height
	// 	* sizeof(int32_t));
	// render(data);
}

void	move_down(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x - player->dir_x * data->m_speed);
	y = (int)player->p_y;
	if (data->map[y][x] != '1')
		player->p_x -= player->dir_x * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y - player->dir_y * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y -= player->dir_y * data->m_speed;
	// ft_memset(data->img->pixels, 0, data->img->width * data->img->height
	// 	* sizeof(int32_t));
	// render(data);
}

void	move_up(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x + player->dir_x * data->m_speed);
	y = (int)(player->p_y);
	if (data->map[y][x] != '1')
		player->p_x += player->dir_x * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y + player->dir_y * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y += player->dir_y * data->m_speed;
	// ft_memset(data->img->pixels, 0, data->img->width * data->img->height
	// 	* sizeof(int32_t));
	// render(data);
}
