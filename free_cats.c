/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:33:14 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 18:33:16 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_catsu(t_data *data)
{
	t_list	*temp;

	while (data->sprites.catsu != NULL)
	{
		temp = data->sprites.catsu;
		data->sprites.catsu = data->sprites.catsu->next;
		mlx_destroy_image(data->mlxdata.mlx, temp->content);
		free(temp->content);
		free(temp);
	}
}

void	free_catsd(t_data *data)
{
	t_list	*temp;

	while (data->sprites.catsd != NULL)
	{
		temp = data->sprites.catsd;
		data->sprites.catsd = data->sprites.catsd->next;
		mlx_destroy_image(data->mlxdata.mlx, temp->content);
		free(temp->content);
		free(temp);
	}
}

void	free_catsl(t_data *data)
{
	t_list	*temp;

	while (data->sprites.catsl != NULL)
	{
		temp = data->sprites.catsl;
		data->sprites.catsl = data->sprites.catsl->next;
		mlx_destroy_image(data->mlxdata.mlx, temp->content);
		free(temp->content);
		free(temp);
	}
}

void	free_catsr(t_data *data)
{
	t_list	*temp;

	while (data->sprites.catsr != NULL)
	{
		temp = data->sprites.catsr;
		data->sprites.catsr = data->sprites.catsr->next;
		mlx_destroy_image(data->mlxdata.mlx, temp->content);
		free(temp->content);
		free(temp);
	}
}
