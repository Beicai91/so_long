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

void	end_game(t_data *data)
{
	int	i;

	i = -1;
	while (data->map_data.map[++i] != NULL)
		free(data->map_data.map[i]);
	free_digits(data);
	free_sprites(data);
	free_catsu(data);
	free_catsd(data);
	free_catsl(data);
	free_catsr(data);
	mlx_destroy_window(data->mlxdata.mlx, data->mlxdata.win);
	// mlx_destroy_display(data->mlxdata.mlx);
	free(data->mlxdata.mlx);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
	{
		move_up(data, keycode);
		display_moves(data);
	}
	if (keycode == KEY_DOWN)
	{
		move_down(data, keycode);
		display_moves(data);
	}
	if (keycode == KEY_LEFT)
	{
		move_left(data, keycode);
		display_moves(data);
	}
	if (keycode == KEY_RIGHT)
	{
		move_right(data, keycode);
		display_moves(data);
	}
	if (keycode == ESC || keycode == SPACE)
		end_game(data);
	return (0);
}

int	cat_on(t_data *data)
{
	if (data->moves != 0)
	{
		if (data->dir_b == 0)
			moveup_catb(data);
		if (data->dir_b == 1)
			movedown_catb(data);
		if (data->dir_b == 2)
			moveleft_catb(data);
		if (data->dir_b == 3)
			moveright_catb(data);
		if (data->dir_j == 0)
			moveright_catj(data);
		if (data->dir_j == 1)
			moveleft_catj(data);
		if (data->dir_j == 2)
			movedown_catj(data);
		if (data->dir_j == 3)
			moveup_catj(data);
	}
	return (0);
}

void	set_temp(t_data *data)
{
	if (data->dir_b == 0)
		data->tempb = data->sprites.catsu;
	if (data->dir_b == 1)
		data->tempb = data->sprites.catsd;
	if (data->dir_b == 2)
		data->tempb = data->sprites.catsl;
	if (data->dir_b == 3)
		data->tempb = data->sprites.catsr;
	if (data->dir_j == 0)
		data->tempj = data->sprites.catsr;
	if (data->dir_j == 1)
		data->tempj = data->sprites.catsl;
	if (data->dir_j == 2)
		data->tempj = data->sprites.catsd;
	if (data->dir_j == 3)
		data->tempj = data->sprites.catsu;
}

void	game_on(t_data *data)
{
	init_data_vars(data);
	render(data);
	set_temp(data);
	mlx_loop_hook(data->mlxdata.mlx, cat_on, data);
	mlx_key_hook(data->mlxdata.win, key_hook, data);
	mlx_loop(data->mlxdata.mlx);
	mlx_destroy_window(data->mlxdata.mlx, data->mlxdata.win);
	// mlx_destroy_display(data->mlxdata.mlx);
	free(data->mlxdata.mlx);
}
