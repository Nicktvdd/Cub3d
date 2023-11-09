/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:48:52 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/09 18:11:43 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-1.0 * data->rot_speed) - player->dir_y
		* sin(-1.0 * data->rot_speed);
	player->dir_y = old_dir_x * sin(-1.0 * data->rot_speed) + player->dir_y
		* cos(-1.0 * data->rot_speed);
	player->plane_x = player->plane_x * cos(-1.0 * data->rot_speed) - player->plane_y
		* sin(-1.0 * data->rot_speed);
	player->plane_y = old_plane_x * sin(-1.0 * data->rot_speed) + player->plane_y
		* cos(-1.0 * data->rot_speed);
	ft_memset(data->img->pixels, 0, data->img->width * data->img->height
			* sizeof(int32_t));
	render(data);
}

void	rotate_right(t_data *data, t_player *player)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(data->rot_speed) - player->dir_y
		* sin(data->rot_speed);
	player->dir_y = old_dir_x * sin(data->rot_speed) + player->dir_y
		* cos(data->rot_speed);
	player->plane_x = player->plane_x * cos(data->rot_speed) - player->plane_y
		* sin(data->rot_speed);
	player->plane_y = old_plane_x * sin(data->rot_speed) + player->plane_y
		* cos(data->rot_speed);
	ft_memset(data->img->pixels, 0, data->img->width * data->img->height
			* sizeof(int32_t));
	render(data);
}