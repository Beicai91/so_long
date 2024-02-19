/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:48:52 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 17:26:07 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_catl1(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL1.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL2.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL3.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL4.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
}

void	init_catl2(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL5.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL6.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL7.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catL8.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsl, cat);
}

void	init_catr1(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR1.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR2.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR3.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR4.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
}

void	init_catr2(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR5.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR6.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR7.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catR8.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsr, cat);
}
