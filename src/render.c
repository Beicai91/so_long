/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:50:39 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 17:24:43 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_data.map[++y] != NULL)
	{
		x = 0;
		while (data->map_data.map[y][x] != '\0')
		{
			if (data->map_data.map[y][x] == '1')
				mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
					data->sprites.wall, SIZE * x, SIZE * y);
			else
				mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
					data->sprites.floor, SIZE * x, SIZE * y);
			x++;
		}
	}
}

void	render_digits(t_data *data)
{
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
		data->digits.zero, (data->map_data.width - 4) / 2 * SIZE,
		(data->map_data.height + 2) * SIZE);
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
		data->digits.zero, ((data->map_data.width - 4) / 2 + 1) * SIZE,
		(data->map_data.height + 2) * SIZE);
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
		data->digits.zero, ((data->map_data.width - 4) / 2 + 2) * SIZE,
		(data->map_data.height + 2) * SIZE);
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
		data->digits.zero, ((data->map_data.width - 4) / 2 + 3) * SIZE,
		(data->map_data.height + 2) * SIZE);
}

void	render_cats(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_data.map[++y] != NULL)
	{
		x = -1;
		while (data->map_data.map[y][++x] != '\0')
		{
			if (data->map_data.map[y][x] == 'B')
			{
				data->catb_pos.x = x;
				data->catb_pos.y = y;
				mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
					data->sprites.catsu->content, SIZE * x, SIZE * y);
			}
			if (data->map_data.map[y][x] == 'J')
			{
				data->catj_pos.x = x;
				data->catj_pos.y = y;
				mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
					data->sprites.catsu->content, SIZE * x, SIZE * y);
			}
		}
	}
}

void	render_other(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_data.map[++y] != NULL)
	{
		x = 0;
		while (data->map_data.map[y][x] != '\0')
		{
			if (data->map_data.map[y][x] == 'P')
				mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
					data->sprites.mouse_front, SIZE * x, SIZE * y);
			if (data->map_data.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
					data->sprites.cheese, SIZE * x, SIZE * y);
			if (data->map_data.map[y][x] == 'E')
				mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
					data->sprites.door_closed, SIZE * x, SIZE * y);
			x++;
		}
	}
}

int	render(t_data *data)
{
	init_sprites(data);
	init_digits(data);
	init_catu1(data);
	init_catu2(data);
	init_catd1(data);
	init_catd2(data);
	init_catl1(data);
	init_catl2(data);
	init_catr1(data);
	init_catr2(data);
	render_background(data);
	render_other(data);
	render_cats(data);
	render_digits(data);
	return (0);
}
