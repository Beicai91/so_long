/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feedback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:52:24 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 16:52:35 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	report_error(char *str, char **map)
{
	int	i;

	ft_printf_basic("%s", str);
	if (map)
	{
		i = 0;
		while (map[i])
			free(map[i++]);
		free(map);
	}
	exit(0);
}
