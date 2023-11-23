/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:04:31 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/23 14:59:40 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_text_path(char *argument)
{
	int	len;

	len = ft_strlen(argument);
	ft_putendl_fd(argument,2);
	if (argument[--len] == 'g' && argument[--len] == 'n'
		&& argument[--len] == 'p' && argument[--len] == '.')
		return (1);
	return (0);
}

int	check_format(char **texture)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		if (!check_text_path(texture[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_data(t_data *data)
{
	if (!check_format(data->texture))
		error_msg("Invalid texture format");
}

int	check_file(char **argument)
{
	int	len;

	len = ft_strlen(argument[1]);
	if (argument[1][--len] == 'b' && argument[1][--len] == 'u'
		&& argument[1][--len] == 'c' && argument[1][--len] == '.')
		return (1);
	return (0);
}