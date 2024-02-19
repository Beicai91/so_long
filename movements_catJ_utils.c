/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_catJ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:55:28 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 17:41:44 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_door_catj(t_data *data)
{
	if (data->collected == data->map_data.collectible)
	{
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catj_pos.x * SIZE, data->catj_pos.y
			* SIZE);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.door_open, data->catj_pos.x * SIZE, data->catj_pos.y
			* SIZE);
	}
	else
	{
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catj_pos.x * SIZE, data->catj_pos.y
			* SIZE);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.door_closed, data->catj_pos.x * SIZE, data->catj_pos.y
			* SIZE);
	}
}

void	catj_non1(t_data *data)
{
	if (data->map_data.map[data->catj_pos.y][data->catj_pos.x] == '0'
		|| data->map_data.map[data->catj_pos.y][data->catj_pos.x] == 'P'
		|| data->map_data.map[data->catj_pos.y][data->catj_pos.x] == 'B'
		|| data->map_data.map[data->catj_pos.y][data->catj_pos.x] == 'J')
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catj_pos.x * SIZE, data->catj_pos.y
			* SIZE);
	else if (data->map_data.map[data->catj_pos.y][data->catj_pos.x] == 'C')
	{
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catj_pos.x * SIZE, data->catj_pos.y
			* SIZE);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.cheese, data->catj_pos.x * SIZE, data->catj_pos.y
			* SIZE);
	}
	else if (data->map_data.map[data->catj_pos.y][data->catj_pos.x] == 'E')
		handle_door_catj(data);
}

void	reset_dir_tempj(t_data *data)
{
	int	r;

	r = rand() % 4;
	while (r == data->dir_j)
		r = rand() % 4;
	data->dir_j = r;
	if (data->dir_j == 0)
		data->tempj = data->sprites.catsr;
	if (data->dir_j == 1)
		data->tempj = data->sprites.catsl;
	if (data->dir_j == 2)
		data->tempj = data->sprites.catsd;
	if (data->dir_j == 3)
		data->tempj = data->sprites.catsu;
}
