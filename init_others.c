/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:50:30 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 16:50:32 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_digits(t_data *data)
{
	data->digits.zero = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/0.xpm", &data->digits.width, &data->digits.height);
	data->digits.one = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/1.xpm", &data->digits.width, &data->digits.height);
	data->digits.two = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/2.xpm", &data->digits.width, &data->digits.height);
	data->digits.three = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/3.xpm", &data->digits.width, &data->digits.height);
	data->digits.four = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/4.xpm", &data->digits.width, &data->digits.height);
	data->digits.five = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/5.xpm", &data->digits.width, &data->digits.height);
	data->digits.six = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/6.xpm", &data->digits.width, &data->digits.height);
	data->digits.seven = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/7.xpm", &data->digits.width, &data->digits.height);
	data->digits.eight = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/8.xpm", &data->digits.width, &data->digits.height);
	data->digits.nine = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/digit/9.xpm", &data->digits.width, &data->digits.height);
}

void	init_sprites(t_data *data)
{
	data->sprites.wall = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/wall2.xpm", &data->sprites.width, &data->sprites.height);
	data->sprites.floor = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/floor.xpm", &data->sprites.width, &data->sprites.height);
	data->sprites.cheese = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/cheese.xpm", &data->sprites.width, &data->sprites.height);
	data->sprites.door_closed = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/door_closed.xpm", &data->sprites.width,
			&data->sprites.height);
	data->sprites.door_open = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/door_open.xpm", &data->sprites.width,
			&data->sprites.height);
	data->sprites.mouse_front = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/mouse_front.xpm", &data->sprites.width,
			&data->sprites.height);
	data->sprites.mouse_back = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/mouse_back.xpm", &data->sprites.width,
			&data->sprites.height);
	data->sprites.mouse_right = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/mouse_right.xpm", &data->sprites.width,
			&data->sprites.height);
	data->sprites.mouse_left = mlx_xpm_file_to_image(data->mlxdata.mlx,
			"sprites/mouse_left.xpm", &data->sprites.width,
			&data->sprites.height);
}
