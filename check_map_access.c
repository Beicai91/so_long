/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:50:08 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 16:50:10 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map_data, t_pos *cur, char **md)
{
	if (md[cur->y][cur->x] == '1' || md[cur->y][cur->x] == 'V' || cur->y < 1
		|| cur->y > map_data->height - 2 || cur->x < 1
		|| cur->x > map_data->width - 2)
		return ;
	if (md[cur->y][cur->x] == 'C')
		map_data->c_num++;
	if (md[cur->y][cur->x] == 'E')
		map_data->e_num++;
	md[cur->y][cur->x] = 'V';
	flood_fill(map_data, &(t_pos){cur->x, cur->y - 1}, md);
	flood_fill(map_data, &(t_pos){cur->x, cur->y + 1}, md);
	flood_fill(map_data, &(t_pos){cur->x - 1, cur->y}, md);
	flood_fill(map_data, &(t_pos){cur->x + 1, cur->y}, md);
}

char	**map_dup(t_map *map_data)
{
	char	**map_dup;
	int		i;

	map_dup = malloc(sizeof(char *) * (map_data->height + 1));
	if (!map_dup)
		return (NULL);
	i = 0;
	while (map_data->map[i] != NULL)
	{
		map_dup[i] = ft_strdup(map_data->map[i]);
		i++;
	}
	map_dup[i] = NULL;
	return (map_dup);
}

void	ft_free(char **map_dup)
{
	int	i;

	i = 0;
	while (map_dup[i] != NULL)
	{
		free(map_dup[i]);
		i++;
	}
	free(map_dup);
}

void	find_pe(t_map *map_data, t_pos *player_pos, t_pos *door_pos)
{
	int	x;
	int	y;

	y = -1;
	while (map_data->map[++y] != NULL)
	{
		x = -1;
		while (map_data->map[y][++x] != '\0')
		{
			if (map_data->map[y][x] == 'P')
			{
				player_pos->x = x;
				player_pos->y = y;
			}
			if (map_data->map[y][x] == 'E')
			{
				door_pos->x = x;
				door_pos->y = y;
			}
		}
	}
}

void	access_check(t_map *map_data, t_pos *player_pos, t_pos *door_pos)
{
	char	**md;

	find_pe(map_data, player_pos, door_pos);
	md = map_dup(map_data);
	flood_fill(map_data, player_pos, md);
	ft_free(md);
	if (map_data->collectible != map_data->c_num)
		report_error("Error\nNot all cheese are accessible!", map_data->map);
	if (map_data->exit != map_data->e_num)
		report_error("Error\nExit not accessible!", map_data->map);
}
