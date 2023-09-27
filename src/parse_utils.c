/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/27 16:10:46 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strstr(char *big, char *little)
{
	size_t	j;

	j = 0;
	if (ft_strlen(little) == 0)
		return (0);
	while (*big != '\0')
	{
		if (*little == *big)
		{
			j = 1;
			while (little[j] == big[j] && little[j] != '\0')
			{
				j++;
			}
			if (little[j] == '\0')
				break ;
		}
		big++;
	}
	if (little[j] == '\0' && big[j] == '\0')
		return (1);
	return (0);
}

int	check_file(char **argument)
{
	if (!ft_strstr(argument[1], ".cub"))
		return (0);
	return (1);
}

int	is_data(char *line, char **info, t_data **data)
{
	if (ft_strnstr(info[0], "NO", ft_strlen(info[0])))
		(*data)->texture[0] = line;
	else if (ft_strnstr(info[0], "SO", ft_strlen(info[0])))
		(*data)->texture[1] = line;
	else if (ft_strnstr(info[0], "WE", ft_strlen(info[0])))
		(*data)->texture[2] = line;
	else if (ft_strnstr(info[0], "EA", ft_strlen(info[0])))
		(*data)->texture[3] = line;
	else if (ft_strnstr(info[0], "F", ft_strlen(info[0])))
		(*data)->color[0] = line;
	else if (ft_strnstr(info[0], "C", ft_strlen(info[0])))
		(*data)->color[1] = line;
	else
		return (0);
	return (1);
}

static int	check_delimiter(char c, char *delimiter)
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

int	is_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	else
	{
		while (line[i])
		{
			if (check_delimiter(line[i], " \f\n\r\t\v"))
				return (1);
			i++;
		}
	}
	return (0);
}
