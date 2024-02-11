#include "so_long.h"

void    handle_door_catB(t_data *data)
{
    if (data->collected == data->map_data.collectible)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catB_pos.x * SIZE, data->catB_pos.y * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_open, data->catB_pos.x * SIZE, data->catB_pos.y * SIZE);
    }
    else
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catB_pos.x * SIZE, data->catB_pos.y * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_closed, data->catB_pos.x * SIZE, data->catB_pos.y * SIZE);
    }
}

void    catB_non1(t_data *data)
{
    if (data->map_data.map[data->catB_pos.y][data->catB_pos.x] == '0' || data->map_data.map[data->catB_pos.y][data->catB_pos.x] == 'P' || data->map_data.map[data->catB_pos.y][data->catB_pos.x] == 'B' ||data->map_data.map[data->catB_pos.y][data->catB_pos.x] == 'J')
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catB_pos.x * SIZE, data->catB_pos.y * SIZE);
    else if (data->map_data.map[data->catB_pos.y][data->catB_pos.x] == 'C')
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catB_pos.x * SIZE, data->catB_pos.y * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.cheese, data->catB_pos.x * SIZE, data->catB_pos.y * SIZE);
    }
    else if (data->map_data.map[data->catB_pos.y][data->catB_pos.x] == 'E')   
        handle_door_catB(data);
}

void    moveup_catB(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catB_pos.x && data->player_pos.y == data->catB_pos.y)
            end_game(data);       
        if (data->tempB == NULL)
            reset_dir_tempB(data);
        if (data->map_data.map[data->catB_pos.y - 1][data->catB_pos.x] != '1' && data->tempB != NULL)
        {
            catB_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempB->content, data->catB_pos.x * SIZE, (data->catB_pos.y - 1) * SIZE);
            data->tempB = data->tempB->next;
            data->catB_pos.y--;
        }
        else if (data->map_data.map[data->catB_pos.y - 1][data->catB_pos.x] == '1')
            reset_dir_tempB(data);
    }
}

void    movedown_catB(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catB_pos.x && data->player_pos.y == data->catB_pos.y)
            end_game(data);
        if (data->tempB == NULL)
            reset_dir_tempB(data);
        if (data->map_data.map[data->catB_pos.y + 1][data->catB_pos.x] != '1' && data->tempB != NULL)
        {
            catB_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempB->content, data->catB_pos.x * SIZE, (data->catB_pos.y + 1) * SIZE);
            data->tempB = data->tempB->next;
            data->catB_pos.y++;
        }
        else if (data->map_data.map[data->catB_pos.y + 1][data->catB_pos.x] == '1')
            reset_dir_tempB(data);
    }
}

void    moveleft_catB(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catB_pos.x && data->player_pos.y == data->catB_pos.y)
            end_game(data);
        if (data->tempB == NULL)
            reset_dir_tempB(data);
        if (data->map_data.map[data->catB_pos.y][data->catB_pos.x - 1] != '1' && data->tempB != NULL)
        {
            catB_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempB->content, (data->catB_pos.x - 1) * SIZE, data->catB_pos.y * SIZE);
            data->tempB = data->tempB->next;
            data->catB_pos.x--;
        }
        else if (data->map_data.map[data->catB_pos.y][data->catB_pos.x - 1] == '1')
            reset_dir_tempB(data);
    }
}

void    moveright_catB(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catB_pos.x && data->player_pos.y == data->catB_pos.y)
            end_game(data);
        if (data->tempB == NULL)
            reset_dir_tempB(data);
        if (data->map_data.map[data->catB_pos.y][data->catB_pos.x + 1] != '1' && data->tempB != NULL)
        {
            catB_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempB->content, (data->catB_pos.x + 1) * SIZE, data->catB_pos.y * SIZE);
            data->tempB = data->tempB->next;
            data->catB_pos.x++;
        }
        else if (data->map_data.map[data->catB_pos.y][data->catB_pos.x + 1] == '1')
            reset_dir_tempB(data);
    }
}

void    reset_dir_tempB(t_data *data)
{
    int r;

    r = rand() % 4;
    while (r == data->directionB)
        r = rand() % 4;
    data->directionB = r;
    if (data->directionB == 0)
        data->tempB = data->sprites.catsU;
    if (data->directionB == 1)
        data->tempB = data->sprites.catsD;
    if (data->directionB == 2)
        data->tempB = data->sprites.catsL;
    if (data->directionB == 3)
        data->tempB = data->sprites.catsR;
}