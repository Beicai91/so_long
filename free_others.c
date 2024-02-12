#include "so_long.h"

void  free_digits(t_data *data)
{
    mlx_destroy_image(data->mlxdata.mlx, data->digits.zero);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.one);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.two);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.three);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.four);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.five);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.six);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.seven);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.eight);
    mlx_destroy_image(data->mlxdata.mlx, data->digits.nine);
}

void    free_sprites(t_data *data)
{
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.wall);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.floor);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.door_closed);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.door_open);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.mouse_back);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.mouse_front);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.mouse_left);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.mouse_right);
    mlx_destroy_image(data->mlxdata.mlx, data->sprites.cheese);
}