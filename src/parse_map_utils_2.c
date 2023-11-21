/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/21 15:03:52 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: check map pre-data
// Checks the file extension if .cub - simplified
int	check_file(char **argument)
{
	int	len;

	len = ft_strlen(argument[1]);
	if (argument[1][--len] == 'b' && argument[1][--len] == 'u'
		&& argument[1][--len] == 'c' && argument[1][--len] == '.')
		return (1);
	return (0);
}

// Parses map data from a line and updates the data structure accordingly
int	is_data(char **info, t_data **data)
{
	char	**new_line;

	new_line = ft_split(info[1], '\n');
	if (!new_line || !new_line[0])
		return (0);
	if (ft_strnstr(info[0], "NO", ft_strlen(info[0])))
		(*data)->texture[0] = ft_strdup(new_line[0]);
	else if (ft_strnstr(info[0], "SO", ft_strlen(info[0])))
		(*data)->texture[1] = ft_strdup(new_line[0]);
	else if (ft_strnstr(info[0], "WE", ft_strlen(info[0])))
		(*data)->texture[2] = ft_strdup(new_line[0]);
	else if (ft_strnstr(info[0], "EA", ft_strlen(info[0])))
		(*data)->texture[3] = ft_strdup(new_line[0]);
	else if (ft_strnstr(info[0], "F", ft_strlen(info[0])))
		(*data)->color[0] = ft_strdup(new_line[0]);
	else if (ft_strnstr(info[0], "C", ft_strlen(info[0])))
		(*data)->color[1] = ft_strdup(new_line[0]);
	else
	{
		free_argt(new_line);
		return (0);
	}
	free_argt(new_line);
	return (1);
}

// Checks if a character is a delimiter
int	check_delimiter(char c, char *delimiter)
{
	int	j;

	j = 0;
	while (delimiter[j] != '\0')
	{
		if (delimiter[j] == c)
			return (1);
		j++;
	}
	return (0);
}

// Checks if a line is empty or contains only whitespace characters
int	is_empty(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0')
		return (1);
	else
	{
		while (line[i])
		{
			if (check_delimiter(line[i], " \f\n\r\t\v"))
				i++;
			else
				return (0);
		}
	}
	return (1);
}
