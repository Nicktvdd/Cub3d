/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:44 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/22 17:28:30 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_speed(t_data *data)
{
	data->m_speed = data->mlx->delta_time * 5.0;
	data->rot_speed = data->mlx->delta_time * 3.0;
}

void	close_game(t_data *data)
{
	free_all(data);
	mlx_close_window(data->mlx);
	exit(0);
}
