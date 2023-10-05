/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:57:50 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/05 11:58:23 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	data_texture(char *line, char **texture)
{
	char	**info;

	info = ft_split(line, " ");
	if (!info[0])
		return (0);
}

static int	parse_map_info(t_data *data, int fd)
{
	char	*line;

	data->texture = (char **)malloc(sizeof(char *) * 5);
	if (!data->texture)
		return (0);
	while (42)
	{
		line = get_next_line(fd);
		if (!data_texture(line, data->texture))
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

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
	if (!parse_map_info(data, data->fd))
		error_msg("wrong map information");
	// if (!parse_map(data->fd))
	// 	error_msg("Invalid map");
}
