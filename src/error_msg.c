/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:52:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/22 17:32:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	error_exit(mlx_t *mlx)
{
	mlx_close_window(mlx);
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	error_free(char *msg, t_data *data)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	free_argt(data->texture);
	exit(1);
}
