/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:52:54 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 16:52:55 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	height_width(int fd, t_map *map_data)
{
	char	*map_line;

	map_line = get_next_line(fd);
	map_data->width = ft_strlen(map_line) - 1;
	while (map_line)
	{
		map_data->height++;
		free(map_line);
		map_line = get_next_line(fd);
		if (map_line != NULL && (int)(ft_strlen(map_line)
			- 1) != map_data->width)
		{
			free(map_line);
			report_error("Error\nMap should be rectangular\n", NULL);
		}
	}
}

void	get_map(char *filename, t_map *map_data)
{
	char	*map_line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		report_error("Error\nMap access failed\n", NULL);
	height_width(fd, map_data);
	close(fd);
	map_data->map = malloc(sizeof(char *) * (map_data->height + 1));
	if (!map_data->map)
		return ;
	fd = open(filename, O_RDONLY);
	map_line = get_next_line(fd);
	i = 0;
	while (map_line)
	{
		map_data->map[i] = ft_strdup(map_line);
		map_data->map[i++][map_data->width] = '\0';
		map_line = get_next_line(fd);
	}
	map_data->map[map_data->height] = NULL;
	close(fd);
}

void	init_map(t_map *map_data)
{
	map_data->width = 0;
	map_data->height = 0;
	map_data->map = NULL;
	map_data->collectible = 0;
	map_data->exit = 0;
	map_data->enemy = 0;
	map_data->player = 0;
	map_data->c_num = 0;
	map_data->e_num = 0;
}

void	map_handling(t_map *map_data, char **argv, t_pos *player_pos,
		t_pos *door_pos)
{
	player_pos->x = 0;
	player_pos->y = 0;
	door_pos->x = 0;
	door_pos->y = 0;
	init_map(map_data);
	get_map(argv[1], map_data);
	handle_map_content(map_data);
	access_check(map_data, player_pos, door_pos);
}
