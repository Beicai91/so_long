/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:53:32 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 17:44:26 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data_vars(t_data *data)
{
	data->collected = 0;
	data->moves = 0;
	data->sprites.catsu = NULL;
	data->sprites.catsd = NULL;
	data->sprites.catsl = NULL;
	data->sprites.catsr = NULL;
	data->dir_b = rand() % 4;
	data->dir_j = rand() % 4;
	data->frames_per_move = 1500;
	data->mlxdata.mlx = mlx_init();
	if (!(data->mlxdata.mlx))
		return ;
	data->mlxdata.win = mlx_new_window(data->mlxdata.mlx, SIZE
			* data->map_data.width, SIZE * (data->map_data.height + 5),
			"Cheese Station N");
	if (!data->mlxdata.win)
	{
		free(data->mlxdata.mlx);
		return ;
	}
}

void	open_door(t_data *data)
{
	if (data->collected == data->map_data.collectible)
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.door_open, data->door_pos.x * SIZE, data->door_pos.y
			* SIZE);
}

void	handle_door(t_data *data, int keycode)
{
	if (data->collected == data->map_data.collectible)
		end_game(data);
	else
	{
		if (keycode == KEY_UP)
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_back, data->door_pos.x * SIZE,
				data->door_pos.y * SIZE);
		if (keycode == KEY_DOWN)
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_front, data->door_pos.x * SIZE,
				data->door_pos.y * SIZE);
		if (keycode == KEY_LEFT)
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_left, data->door_pos.x * SIZE,
				data->door_pos.y * SIZE);
		if (keycode == KEY_RIGHT)
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_right, data->door_pos.x * SIZE,
				data->door_pos.y * SIZE);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y
			* SIZE);
	}
}

void	if_ondoor(t_data *data)
{
	if (!(data->player_pos.x == data->door_pos.x
			&& data->player_pos.y == data->door_pos.y))
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y
			* SIZE);
	else if (data->player_pos.x == data->door_pos.x
		&& data->player_pos.y == data->door_pos.y)
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->sprites.door_closed, data->player_pos.x * SIZE,
			data->player_pos.y * SIZE);
}

void	cover_c(t_data *data, int x, int y, void *mouse)
{
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
		data->sprites.floor, x * SIZE, y * SIZE);
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, mouse, x
		* SIZE, y * SIZE);
	data->map_data.map[y][x] = '0';
}
