/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:14:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/21 08:46:12 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_color(t_data *data)
{
  char **floor_string;
  char **ceiling_string;
  int  floor_nr[3];
  int  ceiling_nr[3];
  int i;

  floor_string = ft_split(data->color[0], ',');
  ceiling_string = ft_split(data->color[1], ',');
  i = -1;
  while (++i < 3)
  {
    if (!floor_string[i] || !ceiling_string[i])
      error_msg("Error loading colors");
    floor_nr[i] = ft_atoi(floor_string[i]);
    ceiling_nr[i] = ft_atoi(ceiling_string[i]);
    if (floor_nr[i] < 0 || ceiling_nr[i] < 0 ||
      floor_nr[i] > 255 || ceiling_nr[i] > 255)
      error_msg("Error loading colors");
  }
  data->floor_c = get_rgb(floor_nr[0], floor_nr[1], floor_nr[2]);
  data->ceiling_c = get_rgb(ceiling_nr[0], ceiling_nr[1], ceiling_nr[2]);
  free_argt(floor_string);
  free_argt(ceiling_string);
  return (0);
}

int check_walls(char **map)
{
  if (!check_first_rc(map))
    return (0);
  if (!check_last_row(map))
    return (0);
  if (!check_last_col(map))
    return (0);
  if (!check_spaces(map))
    return (0);
  return (1);
}

int check_wrong_input(char **map)
{
  int i;
  int j;

  i = 0;
  while (map[i])
  {
    j = 0;
    while (map[i][j] != '\0')
    {
      if (!check_delimiter(map[i][j], MAPCODES))
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

void check_map(char **map)
{
  if (map == NULL)
    error_msg("Empty map");
  if (!check_walls(map))
    error_msg("Map is not surrounded by walls");
  if (!check_wrong_input(map))
    error_msg("Invalid char in the map");
}
