#include "so_long.h"

void    put_digit1(t_data *data, int digit, int offset)
{
    if (digit == 0)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.zero, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 1)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.one, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 2)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.two, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 3)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.three, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 4)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.four, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
}

void    put_digit2(t_data *data, int digit, int offset)
{
    if (digit == 5)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.five, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 6)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.six, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 7)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.seven, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 8)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.eight, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
    if (digit == 9)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.nine, ((data->map_data.width - 4) / 2 + offset) * SIZE, (data->map_data.height + 2) * SIZE);
    }
}

void    display_digit(t_data *data)
{
    int num;
    int digit;
    int offset;

    num = data->moves;
    offset = 3;
    while (num > 0)
    {
        digit = num % 10;
        put_digit1(data, digit, offset);
        put_digit2(data, digit, offset);
        num = num / 10;
        offset--;
    }
}
