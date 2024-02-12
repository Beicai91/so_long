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

void	display_moves(t_data *data)
{
	data->moves++;
	display_digit(data);
}

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
	data->frame_per_move = 1500;
	data->mlxdata.mlx = mlx_init();
	if (!(data->mlxdata.mlx))
		return ;
	data->mlxdata.win = mlx_new_window(data->mlxdata.mlx, SIZE
			* data->map_data.width, SIZE * (data->map_data.height + 5),
			"Cheese Station N");
	if (!data->mlxdata.win)
	{
		// mlx_destroy_display(data->mlxdata.mlx);
		free(data->mlxdata.mlx);
		return ;
	}
}
