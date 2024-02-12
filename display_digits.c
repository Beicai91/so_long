/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:50:55 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 16:51:00 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_digit(t_data *data)
{
	int	num;
	int	digit;
	int	offset;

	num = data->moves;
	offset = 3;
	while (num > 0)
	{
		digit = num % 10;
		put_digit1(data, digit, offset);
		put_digit2(data, digit, offset);
		put_digit3(data, digit, offset);
		put_digit4(data, digit, offset);
		put_digit5(data, digit, offset);
		num = num / 10;
		offset--;
	}
}
