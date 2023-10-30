/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:52:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/30 15:31:26 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	error_exit(mlx_t* mlx)
{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
}