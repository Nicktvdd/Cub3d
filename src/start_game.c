/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/24 18:54:46 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_hook(void *parame)
{
	(void)parame;
	// printf("WIDTH: %d | HEIGHT: %d\n", 100, 50);
}

void	star_mlx(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(W, H, "NICKJUAN", true);
	if (!data->mlx)
		error_msg("Error");
}

void	star_game(t_data *data)
{
	star_mlx(data);
	data->img = mlx_new_image(data->mlx, 256, 256);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
		error_msg("Error");
	mlx_loop_hook(data->mlx, ft_hook, data->mlx);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
