/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:44:56 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/13 15:44:22 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x - player->dir_y * data->m_speed);
	y = (int)player->p_y;
	if (data->map[y][x] != '1')
	{
		player->p_x -= player->dir_y * data->m_speed;
		ft_putendl_fd("BITCH",2);
	}
	ft_putnbr_fd(x,2);
	ft_putchar_fd('\n',2);
	ft_putnbr_fd(y,2);
	ft_putchar_fd('\n',2);
	x = (int)player->p_x;
	y = (int)(player->p_y + player->dir_x * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y += player->dir_x * data->m_speed;
	printf("%f\n",player->p_x);
	printf("%f\n",player->p_y);
	ft_putendl_fd("R",2);
	ft_memset(data->img->pixels, 0, data->img->width * data->img->height
		* sizeof(int32_t));
	render(data);
}

void	move_left(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x + player->dir_y * data->m_speed);
	y = (int)player->p_y;
	if (data->map[y][x] != '1')
		player->p_x += player->dir_y * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y - player->dir_x * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y -= player->dir_x * data->m_speed;
	ft_putnbr_fd(x,2);
	ft_putchar_fd('\n',2);
	printf("%f\n",player->p_x);
	printf("%f\n",player->p_y);
	ft_putendl_fd("L",2);
	ft_memset(data->img->pixels, 0, data->img->width * data->img->height
		* sizeof(int32_t));
	render(data);
}

void	move_down(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x - player->dir_x * data->m_speed);
	y = (int)player->p_y;
	if (data->map[y][x] != '1')
		player->p_x -= player->dir_x * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y - player->dir_y * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y -= player->dir_y * data->m_speed;
	printf("%f\n",player->p_x);
	printf("%f\n",player->p_y);
	ft_putendl_fd("down",2);
	ft_memset(data->img->pixels, 0, data->img->width * data->img->height
		* sizeof(int32_t));
	render(data);
}

void	move_up(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->p_x + player->dir_x * data->m_speed);
	y = (int)(player->p_y);
	if (data->map[y][x] != '1')
		player->p_x += player->dir_x * data->m_speed;
	x = (int)player->p_x;
	y = (int)(player->p_y + player->dir_y * data->m_speed);
	if (data->map[y][x] != '1')
		player->p_y += player->dir_y * data->m_speed;
	printf("%f\n",player->p_x);
	printf("%f\n",player->p_y);
	ft_putendl_fd("up",2);
	ft_memset(data->img->pixels, 0, data->img->width * data->img->height
		* sizeof(int32_t));
	render(data);
}
