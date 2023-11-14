/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:57:50 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/14 11:27:12 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*We have to delete this after test*/

void	print_info(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		ft_putendl_fd(data[i],2);
		i++;
	}
}

int	data_texture_color(char *line, t_data *data, int *i)
{
	char	**info;
	
	info = ft_split(line, ' ');
	if (!info[0])
		return (0);
	if (is_data(line, info, &data))
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
				data->texture[4] = NULL;
				data->color[2] = NULL;
				return (1);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

char	**parse_map(int fd)
{
	char	*line;
	char	*full_map;
	char	**final_map;

	full_map = ft_strdup("");
	line = get_next_line(fd);
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
	if (!parse_map_info(data, fd))
		error_msg("Wrong map information");
	data->map = parse_map(fd);
	print_info(data->color);
	close(fd);
}
