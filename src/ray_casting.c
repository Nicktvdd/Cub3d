/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/07 20:28:08 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_stuff(int x, t_ray *ray, t_data *data)
{
	int	y;

	y = ray->draw_star;
	while (y < ray->draw_end)
	{
		mlx_put_pixel(data->img, x, y, data->wall_c);
		y++;
	}
}

void	ray_casting(t_data *data)
{
	int	x;

	x = 0;
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		error_msg("malloc error");
	while (x < SCREEN_W)
	{
		ray_calculations(data, data->ray, x);
		dda_algorithm(data, data->ray);
		wall_calculations(data->ray);
		draw_stuff(x, data->ray, data);
		x++;
	}
	ft_putendl_fd("HOLA",2);
	if (mlx_image_to_window(data->mlx, data->img, (0), (0)) < 0)
		error_msg("Error");	
}
