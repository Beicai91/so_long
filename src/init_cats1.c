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

void	init_catu1(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU1.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU2.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU3.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU4.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
}

void	init_catu2(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU5.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU6.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU7.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catU8.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsu, cat);
}

void	init_catd1(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD1.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD2.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD3.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD4.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
}

void	init_catd2(t_data *data)
{
	t_list	*cat;

	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD5.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD6.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD7.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
	cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx,
				"sprites/catD8.xpm", &data->sprites.width,
				&data->sprites.height));
	ft_lstadd_back(&data->sprites.catsd, cat);
}
