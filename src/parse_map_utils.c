/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:35:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/23 15:59:51 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	else
	{
		while (line[i])
		{
			if (!check_delimiter(line[i], " \f\n\r\t\v"))
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_map(char *line)
{
	if (line[0] == '\n')
		error_msg("Empty line in map");
	if (!is_empty_line(line))
		return (0);
	return (1);
}

void	get_map_line(char *line, char **temp)
{
	char	*temp2;

	temp2 = ft_strjoin(*temp, line);
	free(*temp);
	*temp = temp2;
}

int	check_wrong_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!check_delimiter(line[i], " 01NSEW\n"))
			return (0);
		i++;
	}
	return (1);
}

char	*find_map(int fd)
{
	char *line;

	line = get_next_line(fd);
	while (line)
	{
		if (is_empty_line(line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!check_wrong_line(line))
		error_msg("Not valid information");
	return (line);
}
