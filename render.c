#include "so_long.h"

void    render_background(t_data *data)
{
    int x;
    int y;

    y = -1;
    while (data->map_data.map[++y] != NULL)
    {
        x = 0;
        while (data->map_data.map[y][x] != '\0')
        {
            if (data->map_data.map[y][x] == '1')
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.wall, SIZE * x, SIZE * y);
            else
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, SIZE * x, SIZE * y);
            x++;
        }
    }
}

void    render_digits(t_data *data)
{
    mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.zero, (data->map_data.width - 4) / 2 * SIZE, (data->map_data.height + 2) * SIZE);
    mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.zero, ((data->map_data.width - 4) / 2 + 1) * SIZE, (data->map_data.height + 2) * SIZE);
    mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.zero, ((data->map_data.width - 4) / 2 + 2)* SIZE, (data->map_data.height + 2) * SIZE);
    mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->digits.zero, ((data->map_data.width - 4) / 2 + 3) * SIZE, (data->map_data.height + 2) * SIZE);
}

void    render_other(t_data *data)
{
    int x;
    int y;
    t_list  *temp;

    y = -1;
    while (data->map_data.map[++y] != NULL)
    {
        x = 0;
        while (data->map_data.map[y][x] != '\0')
        {
            if (data->map_data.map[y][x] == 'P')
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_front, SIZE * x, SIZE * y);
            if (data->map_data.map[y][x] == 'C')
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.cheese, SIZE * x, SIZE * y);
            if (data->map_data.map[y][x] == 'E')
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_closed, SIZE * x, SIZE * y);
            if (data->map_data.map[y][x] == 'B')
            {
                data->catB_pos.x = x;
                data->catB_pos.y = y;
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.catsU->content, SIZE * x, SIZE * y);
            }
            if (data->map_data.map[y][x] == 'J')
            {
                data->catJ_pos.x = x;
                data->catJ_pos.y = y;
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.catsU->content, SIZE * x, SIZE * y);
            }
            x++;
        }
    }
}

int    render(t_data *data)
{
    init_sprites(data);
    init_digits(data);
    init_catU(data);
    init_catD(data);
    init_catL(data);
    init_catR(data);
    render_background(data);
    render_other(data);
    render_digits(data);
    return (0);
}