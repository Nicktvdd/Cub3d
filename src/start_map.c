/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:57:50 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/26 17:57:24 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	data_texture_color(char *line, t_data *data, int *i)
{
	char	**info;

	info = ft_split(line, ' ');
	if (!info[0])
		return (0);
	if (is_data(line, info, data))
	{
		free_argt(info);
		i++;
		return (1);
	}
	else if (is_empty(line))
	{
		free_argt(info);
		return (1);
	}
	else
	{
		free_argt(info);
		return (0);
	}
}

static int	parse_map_info(t_data *data, int fd)
{
	char	*line;
	int		counter;

	data->texture = (char **)malloc(sizeof(char *) * 5);
	if (!data->texture)
		error_msg("Allocation error");
	data->color = (char **)malloc(sizeof(char *) * 2);
	if (!data->color)
		error_msg("Allocation error");
	counter = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (data_texture_color(line, data, &counter))
		{
			if (counter == 6)
			{
				free(line);
				return (1);
			}
		}
		free(line);
	}
	if (counter != 6)
		return (0);
}

static int	parse_map(int fd)
{
	char	*line;
	char	*full_map;
	char	**final_map;

	full_map = NULL;
	while (line)
	{
		line = get_next_line(fd);
		if (is_map(line))
			full_map = ft_strjoin(full_map, line);
		free(line);
	}
	final_map = ft_split(full_map, '\n');
	if (!final_map[0])
		free_argt_exit(final_map);
	free(full_map);
	return (final_map);
}

void	init_map(t_data *data, char **argv)
{
	if (!check_file(argv))
		error_msg("Error, invalid file format");
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		error_msg("Error file descriptor");
	if (!parse_map_info(data, data->fd))
		error_msg("Wrong map information");
	data->map = parse_map(data->fd);
}
