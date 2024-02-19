/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:47 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 16:49:50 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int keycode)
{
	char	next;

	next = data->map_data.map[data->player_pos.y - 1][data->player_pos.x];
	if (next != '1')
	{
		if (next == '0' || next == 'P' || next == 'B' || next == 'J')
		{
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_back, data->player_pos.x * SIZE,
				(data->player_pos.y - 1) * SIZE);
			if_ondoor(data);
		}
		else if (next == 'C')
		{
			cover_c(data, data->player_pos.x, data->player_pos.y - 1,
				data->sprites.mouse_back);
			if_ondoor(data);
			data->collected++;
		}
		else if (next == 'E')
			handle_door(data, keycode);
		open_door(data);
		data->player_pos.y--;
	}
}

void	move_down(t_data *data, int keycode)
{
	char	next;

	next = data->map_data.map[data->player_pos.y + 1][data->player_pos.x];
	if (next != '1')
	{
		if (next == '0' || next == 'P' || next == 'B' || next == 'J')
		{
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_front, data->player_pos.x * SIZE,
				(data->player_pos.y + 1) * SIZE);
			if_ondoor(data);
		}
		else if (next == 'C')
		{
			cover_c(data, data->player_pos.x, data->player_pos.y + 1,
				data->sprites.mouse_front);
			if_ondoor(data);
			data->collected++;
		}
		else if (next == 'E')
			handle_door(data, keycode);
		open_door(data);
		data->player_pos.y++;
	}
}

void	move_left(t_data *data, int keycode)
{
	char	next;

	next = data->map_data.map[data->player_pos.y][data->player_pos.x - 1];
	if (next != '1')
	{
		if (next == '0' || next == 'P' || next == 'B' || next == 'J')
		{
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_left, (data->player_pos.x - 1) * SIZE,
				data->player_pos.y * SIZE);
			if_ondoor(data);
		}
		else if (next == 'C')
		{
			cover_c(data, data->player_pos.x - 1, data->player_pos.y,
				data->sprites.mouse_left);
			if_ondoor(data);
			data->collected++;
		}
		else if (next == 'E')
			handle_door(data, keycode);
		open_door(data);
		data->player_pos.x--;
	}
}

void	move_right(t_data *data, int keycode)
{
	char	next;

	next = data->map_data.map[data->player_pos.y][data->player_pos.x + 1];
	if (next != '1')
	{
		if (next == '0' || next == 'P' || next == 'B' || next == 'J')
		{
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->sprites.mouse_right, (data->player_pos.x + 1) * SIZE,
				data->player_pos.y * SIZE);
			if_ondoor(data);
		}
		else if (next == 'C')
		{
			cover_c(data, data->player_pos.x + 1, data->player_pos.y,
				data->sprites.mouse_right);
			if_ondoor(data);
			data->collected++;
		}
		else if (next == 'E')
			handle_door(data, keycode);
		open_door(data);
		data->player_pos.x++;
	}
}
