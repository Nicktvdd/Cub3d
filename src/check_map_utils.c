/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:37 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/14 14:36:51 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_spaces(char **map)
{
	int	i;
	int	j;
	int len;
	int nextlen;

	i = 0;
	j = 0;
	len = 0;
	while (map[i])
	{
		if (map[i + 1])
			nextlen = ft_strlen(map[i + 1]);
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || j == 0)
					return (0);
				if (j >= len || j >= nextlen)
					return (0);
				if (!map[i + 1] || !map[i][j + 1] || !map[i + 1][j])
					return (0);
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
					return (0);
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					return (0);
				// return 0 if error
			}
			j++;
		}
		len = ft_strlen(map[i]);
		printf("strlen:%i\n", len);
		i++;
		j = 0;
		
	}
	return (1);
}

int	get_map_height(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (map[i])
	{
		height++;
		i++;
	}
	return (height);
}

int	check_first_rc(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = get_map_height(map);
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' && map[0][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_last_row(char **map)
{
	int	i;
	int	n_rows;

	i = 0;
	n_rows = get_map_height(map);
	while (map[n_rows - 1][i] != '\0')
	{
		if (map[n_rows - 1][i] != '1' && map[n_rows - 1][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_last_col(char **map)
{
	int		i;
	size_t	row_len;

	i = 0;
	while (map[i])
	{
		row_len = ft_strlen(map[i]);
		if (row_len > 0 && (map[i][row_len - 1] != '1' && map[i][row_len
				- 1] != ' '))
			return (0);
		i++;
	}
	return (1);
}
