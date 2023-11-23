/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:57:50 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/23 16:01:14 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	data_texture_color(char *line, t_data *data, int *i)
{
	char	**info;

	info = ft_split(line, ' ');
	if (!info[0])
		return (0);
	if (info[1] && (info[2] && is_space_line(info[2])))
		error_msg("Wrong map information");
	if (is_data(info, &data))
	{
		free_argt(info);
		(*i)++;
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

int	parse_map_info(t_data *data, int fd)
{
	char	*line;
	int		counter;

	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (data_texture_color(line, data, &counter))
		{
			if (counter == 6)
			{
				free(line);
				check_color(data);
				return (1);
			}
		}
		else
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

char	**parse_map(int fd)
{
	char	*line;
	char	*full_map;
	char	**final_map;
	int		i;

	i = 0;
	full_map = ft_strdup("");
	line = find_map(fd);
	while (line)
	{
		if (is_map(line))
			get_map_line(line, &full_map);
		free(line);
		line = get_next_line(fd);
	}
	final_map = ft_split(full_map, '\n');
	if (!final_map[0] || !final_map)
		free_argt_exit(final_map);
	free(full_map);
	return (final_map);
}

void	init_info(t_data *data)
{
	data->texture[0] = NULL;
	data->texture[1] = NULL;
	data->texture[2] = NULL;
	data->texture[3] = NULL;
	data->texture[4] = NULL;
	data->color[0] = NULL;
	data->color[1] = NULL;
	data->color[2] = NULL;
}

void	init_map(t_data *data, char **argv)
{
	int	fd;

	if (!check_file(argv))
		error_msg("Error, invalid file format");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg("Error file descriptor");
	data->texture = (char **)malloc(sizeof(char *) * 5);
	if (!data->texture)
		error_msg("Allocation error");
	data->color = (char **)malloc(sizeof(char *) * 3);
	if (!data->color)
		error_msg("Allocation error");
	init_info(data);
	if (!parse_map_info(data, fd))
		error_msg("Wrong map information");
	data->map = parse_map(fd);
	close(fd);
}
