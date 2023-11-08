/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:44 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/08 18:23:12 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_speed(t_data *data)
{
	data->frameTime = 12 / 1000.0;
	data->m_speed = data->frameTime * 5.0;
	data->rot_speed = data->frameTime * 3.0;
}
