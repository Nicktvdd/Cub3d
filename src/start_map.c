/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:57:50 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/20 15:37:41 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file(char **argument)
{
	if (!ft_strstr(argument[1], ".cub"))
		return (0);
	return (1);
}

void	init_map(t_data *data, char **argv)
{
	if (!check_file(argv))
		error_msg("Error, invalid file format");
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		error_msg("Error file descriptor");
	// if (!parse_map_info(data->fd))
	// 	error_msg("wrong map information");
	// if (!parse_map(data->fd))
	// 	error_msg("Invalid map");
}
