/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_catb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:55:01 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 18:49:21 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_door_catb(t_data *data)
{
	if (data->collected == data->map_data.collectible)
	{
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catb_pos.x * SIZE, data->catb_pos.y
			* SIZE);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.door_open, data->catb_pos.x * SIZE, data->catb_pos.y
			* SIZE);
	}
	else
	{
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catb_pos.x * SIZE, data->catb_pos.y
			* SIZE);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.door_closed, data->catb_pos.x * SIZE, data->catb_pos.y
			* SIZE);
	}
}

void	catb_non1(t_data *data)
{
	if (data->map_data.map[data->catb_pos.y][data->catb_pos.x] == '0'
		|| data->map_data.map[data->catb_pos.y][data->catb_pos.x] == 'P'
		|| data->map_data.map[data->catb_pos.y][data->catb_pos.x] == 'B'
		|| data->map_data.map[data->catb_pos.y][data->catb_pos.x] == 'J')
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catb_pos.x * SIZE, data->catb_pos.y
			* SIZE);
	else if (data->map_data.map[data->catb_pos.y][data->catb_pos.x] == 'C')
	{
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->catb_pos.x * SIZE, data->catb_pos.y
			* SIZE);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.cheese, data->catb_pos.x * SIZE, data->catb_pos.y
			* SIZE);
	}
	else if (data->map_data.map[data->catb_pos.y][data->catb_pos.x] == 'E')
		handle_door_catb(data);
}

void	reset_dir_tempb(t_data *data)
{
	int	r;

	r = rand() % 4;
	while (r == data->dir_b)
		r = rand() % 4;
	data->dir_b = r;
	if (data->dir_b == 0)
		data->tempb = data->sprites.catsu;
	if (data->dir_b == 1)
		data->tempb = data->sprites.catsd;
	if (data->dir_b == 2)
		data->tempb = data->sprites.catsl;
	if (data->dir_b == 3)
		data->tempb = data->sprites.catsr;
}
