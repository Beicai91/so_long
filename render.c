#include "so_long.h"

void    init_sprites(t_data *data)
{
    data->sprites.wall = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/wall2.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.floor = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/floor.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.cheese = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/cheese.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.door_closed = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/door_closed.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.door_open = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/door_open.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.mouse_front = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/mouse_front.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.mouse_back = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/mouse_back.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.mouse_right = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/mouse_right.xpm", &data->sprites.width, &data->sprites.height);
    data->sprites.mouse_left = mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/mouse_left.xpm", &data->sprites.width, &data->sprites.height);
}


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
    init_catU(data);
    init_catD(data);
    init_catL(data);
    init_catR(data);
    render_background(data);
    render_other(data);
    return (0);
}