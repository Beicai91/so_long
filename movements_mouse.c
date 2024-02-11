#include "so_long.h"

void    open_door(t_data *data)
{
    if (data->collected == data->map_data.collectible)
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_open, data->door_pos.x * SIZE, data->door_pos.y * SIZE);
}

void    handle_door(t_data *data, int keycode)
{
    if (data->collected == data->map_data.collectible)
        end_game(data);
    else
    {
        if (keycode == KEY_UP)
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_back, data->door_pos.x * SIZE, data->door_pos.y * SIZE);
        if (keycode == KEY_DOWN)
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_front, data->door_pos.x * SIZE, data->door_pos.y * SIZE);
        if (keycode == KEY_LEFT)
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_left, data->door_pos.x * SIZE, data->door_pos.y * SIZE);
        if (keycode == KEY_RIGHT)
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_right, data->door_pos.x * SIZE, data->door_pos.y * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
    }
}

void    move_up(t_data *data, int keycode)
{
    if (data->map_data.map[data->player_pos.y - 1][data->player_pos.x] != '1')
    {
        if (data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == '0' || data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'P'|| data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'B'|| data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'J')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_back, data->player_pos.x * SIZE, (data->player_pos.y - 1) * SIZE);
            if (!(data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y))
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            else if (data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y)
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_closed, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
        }
        else if (data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'C')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, (data->player_pos.y - 1) * SIZE);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_back, data->player_pos.x * SIZE, (data->player_pos.y - 1) * SIZE);
            data->map_data.map[data->player_pos.y - 1][data->player_pos.x] = '0';
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            data->collected++;
        }
        else if (data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'E')
            handle_door(data, keycode);
        open_door(data);
        data->player_pos.y--;
    }
}

void    move_down(t_data *data, int keycode)
{
    if (data->map_data.map[data->player_pos.y + 1][data->player_pos.x] != '1')
    {
        if (data->map_data.map[data->player_pos.y + 1][data->player_pos.x] == '0' || data->map_data.map[data->player_pos.y + 1][data->player_pos.x] == 'P'|| data->map_data.map[data->player_pos.y + 1][data->player_pos.x] == 'B'|| data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'J')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_front, data->player_pos.x * SIZE, (data->player_pos.y + 1) * SIZE);
            if (!(data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y))
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            else if (data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y)
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_closed, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            }
        else if (data->map_data.map[data->player_pos.y + 1][data->player_pos.x] == 'C')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, (data->player_pos.y + 1) * SIZE);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_front, data->player_pos.x * SIZE, (data->player_pos.y + 1) * SIZE);
            data->map_data.map[data->player_pos.y + 1][data->player_pos.x] = '0';
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            data->collected++;
        }
        else if (data->map_data.map[data->player_pos.y + 1][data->player_pos.x] == 'E')
            handle_door(data, keycode);
        open_door(data);
        data->player_pos.y++;
    }
}

void    move_left(t_data *data, int keycode)
{
    if (data->map_data.map[data->player_pos.y][data->player_pos.x - 1] != '1')
    {
        if (data->map_data.map[data->player_pos.y][data->player_pos.x - 1] == '0' || data->map_data.map[data->player_pos.y][data->player_pos.x - 1] == 'P'|| data->map_data.map[data->player_pos.y][data->player_pos.x - 1] == 'B'|| data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'J')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_left, (data->player_pos.x - 1) * SIZE, data->player_pos.y * SIZE);
            if (!(data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y))
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            else if (data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y)
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_closed, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
        }
        else if (data->map_data.map[data->player_pos.y][data->player_pos.x - 1] == 'C')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, (data->player_pos.x - 1) * SIZE, data->player_pos.y * SIZE);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_left, (data->player_pos.x - 1) * SIZE, data->player_pos.y * SIZE);
            data->map_data.map[data->player_pos.y][data->player_pos.x - 1] = '0';
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            data->collected++;
        }
        else if (data->map_data.map[data->player_pos.y][data->player_pos.x - 1] == 'E')
            handle_door(data, keycode);
        open_door(data);
        data->player_pos.x--;
    }
}

void    move_right(t_data *data, int keycode)
{
    if (data->map_data.map[data->player_pos.y][data->player_pos.x + 1] != '1')
    {
        if (data->map_data.map[data->player_pos.y][data->player_pos.x + 1] == '0' || data->map_data.map[data->player_pos.y][data->player_pos.x + 1] == 'P'|| data->map_data.map[data->player_pos.y][data->player_pos.x + 1] == 'B' || data->map_data.map[data->player_pos.y - 1][data->player_pos.x] == 'J')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_right, (data->player_pos.x + 1) * SIZE, data->player_pos.y * SIZE);
            if (!(data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y))
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            else if (data->player_pos.x == data->door_pos.x && data->player_pos.y == data->door_pos.y)
                mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_closed, data->player_pos.x * SIZE, data->player_pos.y * SIZE);

        }
        else if (data->map_data.map[data->player_pos.y][data->player_pos.x + 1] == 'C')
        {
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, (data->player_pos.x + 1) * SIZE, data->player_pos.y * SIZE);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.mouse_right, (data->player_pos.x + 1) * SIZE, data->player_pos.y * SIZE);
            data->map_data.map[data->player_pos.y][data->player_pos.x + 1] = '0';
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->player_pos.x * SIZE, data->player_pos.y * SIZE);
            data->collected++;
        }
        else if (data->map_data.map[data->player_pos.y][data->player_pos.x + 1] == 'E')
            handle_door(data, keycode);
        open_door(data);
        data->player_pos.x++;
    }
}
