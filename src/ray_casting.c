/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/03 17:54:43 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting(t_data *data)
{
	int x;

	x = 0;
	while (x < SCREEN_W)
	{
		ray_calculations(data, x);
		dda_algorithm(data);
		high_of_wall(data);
	}
}