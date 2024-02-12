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

void	moveup_catb(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catb_pos.x
			&& data->player_pos.y == data->catb_pos.y)
			end_game(data);
		if (data->tempb == NULL)
			reset_dir_tempb(data);
		if (data->map_data.map[data->catb_pos.y - 1][data->catb_pos.x] != '1'
			&& data->tempb != NULL)
		{
			catb_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempb->content, data->catb_pos.x * SIZE, (data->catb_pos.y
					- 1) * SIZE);
			data->tempb = data->tempb->next;
			data->catb_pos.y--;
		}
		else if (data->map_data.map[data->catb_pos.y
				- 1][data->catb_pos.x] == '1')
			reset_dir_tempb(data);
	}
}

void	movedown_catb(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catb_pos.x
			&& data->player_pos.y == data->catb_pos.y)
			end_game(data);
		if (data->tempb == NULL)
			reset_dir_tempb(data);
		if (data->map_data.map[data->catb_pos.y + 1][data->catb_pos.x] != '1'
			&& data->tempb != NULL)
		{
			catb_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempb->content, data->catb_pos.x * SIZE, (data->catb_pos.y
					+ 1) * SIZE);
			data->tempb = data->tempb->next;
			data->catb_pos.y++;
		}
		else if (data->map_data.map[data->catb_pos.y
				+ 1][data->catb_pos.x] == '1')
			reset_dir_tempb(data);
	}
}

void	moveleft_catb(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catb_pos.x
			&& data->player_pos.y == data->catb_pos.y)
			end_game(data);
		if (data->tempb == NULL)
			reset_dir_tempb(data);
		if (data->map_data.map[data->catb_pos.y][data->catb_pos.x - 1] != '1'
			&& data->tempb != NULL)
		{
			catb_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempb->content, (data->catb_pos.x - 1) * SIZE,
				data->catb_pos.y * SIZE);
			data->tempb = data->tempb->next;
			data->catb_pos.x--;
		}
		else if (data->map_data.map[data->catb_pos.y][data->catb_pos.x
			- 1] == '1')
			reset_dir_tempb(data);
	}
}

void	moveright_catb(t_data *data)
{
	static int	frame_counter = 0;
	int			frames_per_move;

	frames_per_move = 1500;
	frame_counter++;
	if (frame_counter >= frames_per_move)
	{
		frame_counter = 0;
		if (data->player_pos.x == data->catb_pos.x
			&& data->player_pos.y == data->catb_pos.y)
			end_game(data);
		if (data->tempb == NULL)
			reset_dir_tempb(data);
		if (data->map_data.map[data->catb_pos.y][data->catb_pos.x + 1] != '1'
			&& data->tempb != NULL)
		{
			catb_non1(data);
			mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
				data->tempb->content, (data->catb_pos.x + 1) * SIZE,
				data->catb_pos.y * SIZE);
			data->tempb = data->tempb->next;
			data->catb_pos.x++;
		}
		else if (data->map_data.map[data->catb_pos.y][data->catb_pos.x
			+ 1] == '1')
			reset_dir_tempb(data);
	}
}
