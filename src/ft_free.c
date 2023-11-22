/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:09:39 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/22 13:05:37 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_argt(char **argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		free(argument[i]);
		argument[i] = NULL;
		i++;
	}
	free(argument);
}

void	free_argt_exit(char **argument)
{
	free_argt(argument);
	error_msg("Error, empty map");
}

void	free_all(t_data *data)
{
	free_argt(data->map);
	free_argt(data->color);
	free_argt(data->texture);
	free(data->player);
	free(data->ray);
	mlx_delete_texture(data->text_1);
	mlx_delete_texture(data->text_2);
	mlx_delete_texture(data->text_3);
	mlx_delete_texture(data->text_4);
}
