/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:13 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 16:52:11 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		report_error("Error\nArguments have to be two!\n", NULL);
	i = 0;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (ft_strnstr(&argv[1][i], ".ber", 4) == NULL || ft_strlen(argv[1])
		- i != 4)
		report_error("Error\nFile format should be \".ber\"\n", NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc, argv);
	map_handling(&(data.map_data), argv, &(data.player_pos), &(data.door_pos));
	game_on(&data);
	return (0);
}
