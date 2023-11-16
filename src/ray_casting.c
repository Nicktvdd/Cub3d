/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/16 19:23:49 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_color(t_data *data, t_ray *ray)
{
	int	color;
	int	x;
	int	y;
	int	index;

	y = ray->text_y * data->text_to_draw->height;
	x = ray->text_x * data->text_to_draw->width;
	index = y * data->text_to_draw->bytes_per_pixel * data->text_to_draw->width
		+ x * data->text_to_draw->bytes_per_pixel;
	printf("%d\n", data->text_to_draw->pixels[0]);
	color = data->text_to_draw->pixels[index] << 24 | data->text_to_draw->pixels[index
		+ 1] << 16 | data->text_to_draw->pixels[index + 2] << 8 | 0xFF;
	return (color);
}

void	select_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->map_x > data->player->p_x)
			data->text_to_draw = data->text_1;
		else
			data->text_to_draw = data->text_2;
	}
	else if (ray->side == 1)
	{
		if (ray->map_y > data->player->p_y)
			data->text_to_draw = data->text_3;
		else
			data->text_to_draw = data->text_4;
	}
}

void	texturing_calculations(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = data->player->p_y + ray->perp_dist * ray->raydir_y;
	else
		ray->wall_x = data->player->p_x + ray->perp_dist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->text_x = (int)(ray->wall_x * (double)TEXTURE_W);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->text_x = TEXTURE_W - ray->text_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->text_x = TEXTURE_W - ray->text_x - 1;
}

void	draw_stuff(int x, t_ray *ray, t_data *data)
{
	int		y;
	double	step;
	double	texture_pos;

	y = ray->draw_star;
	step = 1.0 * ((double)TEXTURE_H) / ray->line_height;
	texture_pos = (ray->draw_star - (SCREEN_H / 2) + (ray->line_height / 2))
		* step;
	while (y < ray->draw_end)
	{
		ray->text_y = (int)texture_pos & (TEXTURE_H - 1);
		texture_pos += step;
		/*TODO: We have to find nice textures, and recreat here,
			and then decide the wall color */
		// if (ray->side == 1)
		// 	data->wall_c = (data->wall_c >> 1) & 8355711;
		data->wall_c = wall_color(data, ray);
		mlx_put_pixel(data->img, x, y, data->wall_c);
		y++;
	}
}

void	ray_casting(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_W)
	{
		ray_calculations(data, data->ray, x);
		dda_algorithm(data, data->ray);
		wall_calculations(data->ray);
		select_texture(data, data->ray);
		texturing_calculations(data, data->ray);
		draw_stuff(x, data->ray, data);
		x++;
	}
}
