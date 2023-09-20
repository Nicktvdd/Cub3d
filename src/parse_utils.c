/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/20 15:33:45 by jpelaez-         ###   ########.fr       */
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