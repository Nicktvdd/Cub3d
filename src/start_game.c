/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/24 18:34:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void ft_hook(void* parame)
{
	(void)parame;
	// printf("WIDTH: %d | HEIGHT: %d\n", 100, 50);
}

void	start_game(t_data *data)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	(void)data;
	ft_putendl_fd("uno",2);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(W, H, "NICKJUAN", true);
	if (!mlx)
		error_msg("Error");
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		 error_msg("Error");
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
