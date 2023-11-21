/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:35:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/21 17:27:50 by jpelaez-         ###   ########.fr       */
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
	if (line[0] == '\n' || !line)
		return (0);
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
