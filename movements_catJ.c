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

void	moveup_catj(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catj_pos.x
			&& data->player_pos.y == data->catj_pos.y)
			end_game(data);
		if (data->tempj == NULL)
			reset_dir_tempj(data);
		if (data->map_data.map[data->catj_pos.y - 1][data->catj_pos.x] != '1'
			&& data->tempj != NULL)
		{
			catj_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempj->content, data->catj_pos.x * SIZE, (data->catj_pos.y
					- 1) * SIZE);
			data->tempj = data->tempj->next;
			data->catj_pos.y--;
		}
		else if (data->map_data.map[data->catj_pos.y
				- 1][data->catj_pos.x] == '1')
			reset_dir_tempj(data);
	}
}

void	movedown_catj(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catj_pos.x
			&& data->player_pos.y == data->catj_pos.y)
			end_game(data);
		if (data->tempj == NULL)
			reset_dir_tempj(data);
		if (data->map_data.map[data->catj_pos.y + 1][data->catj_pos.x] != '1'
			&& data->tempj != NULL)
		{
			catj_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempj->content, data->catj_pos.x * SIZE, (data->catj_pos.y
					+ 1) * SIZE);
			data->tempj = data->tempj->next;
			data->catj_pos.y++;
		}
		else if (data->map_data.map[data->catj_pos.y
				+ 1][data->catj_pos.x] == '1')
			reset_dir_tempj(data);
	}
}

void	moveleft_catj(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catj_pos.x
			&& data->player_pos.y == data->catj_pos.y)
			end_game(data);
		if (data->tempj == NULL)
			reset_dir_tempj(data);
		if (data->map_data.map[data->catj_pos.y][data->catj_pos.x - 1] != '1'
			&& data->tempj != NULL)
		{
			catj_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempj->content, (data->catj_pos.x - 1) * SIZE,
				data->catj_pos.y * SIZE);
			data->tempj = data->tempj->next;
			data->catj_pos.x--;
		}
		else if (data->map_data.map[data->catj_pos.y][data->catj_pos.x
			- 1] == '1')
			reset_dir_tempj(data);
	}
}

void	moveright_catj(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catj_pos.x
			&& data->player_pos.y == data->catj_pos.y)
			end_game(data);
		if (data->tempj == NULL)
			reset_dir_tempj(data);
		if (data->map_data.map[data->catj_pos.y][data->catj_pos.x + 1] != '1'
			&& data->tempj != NULL)
		{
			catj_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempj->content, (data->catj_pos.x + 1) * SIZE,
				data->catj_pos.y * SIZE);
			data->tempj = data->tempj->next;
			data->catj_pos.x++;
		}
		else if (data->map_data.map[data->catj_pos.y][data->catj_pos.x
			+ 1] == '1')
			reset_dir_tempj(data);
	}
}
