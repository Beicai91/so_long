
#include "so_long.h"

void    handle_door_catJ(t_data *data)
{
    if (data->collected == data->map_data.collectible)
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catJ_pos.x * SIZE, data->catJ_pos.y * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_open, data->catJ_pos.x * SIZE, data->catJ_pos.y * SIZE);
    }
    else
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catJ_pos.x * SIZE, data->catJ_pos.y * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.door_closed, data->catJ_pos.x * SIZE, data->catJ_pos.y * SIZE);
    }
}

void    catJ_non1(t_data *data)
{
    if (data->map_data.map[data->catJ_pos.y][data->catJ_pos.x] == '0' || data->map_data.map[data->catJ_pos.y][data->catJ_pos.x] == 'P' || data->map_data.map[data->catJ_pos.y][data->catJ_pos.x] == 'B' ||data->map_data.map[data->catJ_pos.y][data->catJ_pos.x] == 'J')
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catJ_pos.x * SIZE, data->catJ_pos.y * SIZE);
    else if (data->map_data.map[data->catJ_pos.y][data->catJ_pos.x] == 'C')
    {
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.floor, data->catJ_pos.x * SIZE, data->catJ_pos.y * SIZE);
        mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->sprites.cheese, data->catJ_pos.x * SIZE, data->catJ_pos.y * SIZE);
    }
    else if (data->map_data.map[data->catJ_pos.y][data->catJ_pos.x] == 'E')   
        handle_door_catJ(data);
}

void    moveup_catJ(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catJ_pos.x && data->player_pos.y == data->catJ_pos.y)
            end_game(data);       
        if (data->tempJ == NULL)
            reset_dir_tempJ(data);
        if (data->map_data.map[data->catJ_pos.y - 1][data->catJ_pos.x] != '1' && data->tempJ != NULL)
        {
            catJ_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempJ->content, data->catJ_pos.x * SIZE, (data->catJ_pos.y - 1) * SIZE);
            data->tempJ = data->tempJ->next;
            data->catJ_pos.y--;
        }
        else if (data->map_data.map[data->catJ_pos.y - 1][data->catJ_pos.x] == '1')
            reset_dir_tempJ(data);
    }
}

void    movedown_catJ(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catJ_pos.x && data->player_pos.y == data->catJ_pos.y)
            end_game(data);
        if (data->tempJ == NULL)
            reset_dir_tempJ(data);
        if (data->map_data.map[data->catJ_pos.y + 1][data->catJ_pos.x] != '1' && data->tempJ != NULL)
        {
            catJ_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempJ->content, data->catJ_pos.x * SIZE, (data->catJ_pos.y + 1) * SIZE);
            data->tempJ = data->tempJ->next;
            data->catJ_pos.y++;
        }
        else if (data->map_data.map[data->catJ_pos.y + 1][data->catJ_pos.x] == '1')
            reset_dir_tempJ(data);
    }
}

void    moveleft_catJ(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catJ_pos.x && data->player_pos.y == data->catJ_pos.y)
            end_game(data);
        if (data->tempJ == NULL)
            reset_dir_tempJ(data);
        if (data->map_data.map[data->catJ_pos.y][data->catJ_pos.x - 1] != '1' && data->tempJ != NULL)
        {
            catJ_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempJ->content, (data->catJ_pos.x - 1) * SIZE, data->catJ_pos.y * SIZE);
            data->tempJ = data->tempJ->next;
            data->catJ_pos.x--;
        }
        else if (data->map_data.map[data->catJ_pos.y][data->catJ_pos.x - 1] == '1')
            reset_dir_tempJ(data);
    }
}

void    moveright_catJ(t_data *data)
{
    static int  frame_counter = 0;
    const int   frames_per_move = 1500;

    frame_counter++;
    if (frame_counter >= frames_per_move)
    {
        frame_counter = 0;
        if (data->player_pos.x == data->catJ_pos.x && data->player_pos.y == data->catJ_pos.y)
            end_game(data);
        if (data->tempJ == NULL)
            reset_dir_tempJ(data);
        if (data->map_data.map[data->catJ_pos.y][data->catJ_pos.x + 1] != '1' && data->tempJ != NULL)
        {
            catJ_non1(data);
            mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win, data->tempJ->content, (data->catJ_pos.x + 1) * SIZE, data->catJ_pos.y * SIZE);
            data->tempJ = data->tempJ->next;
            data->catJ_pos.x++;
        }
        else if (data->map_data.map[data->catJ_pos.y][data->catJ_pos.x + 1] == '1')
            reset_dir_tempJ(data);
    }
}

void    reset_dir_tempJ(t_data *data)
{
    int r;

    r = rand() % 4;
    while (r == data->directionJ)
        r = rand() % 4;
    data->directionJ = r;
    if (data->directionJ == 0)
        data->tempJ = data->sprites.catsR;
    if (data->directionJ == 1)
        data->tempJ = data->sprites.catsL;
    if (data->directionJ == 2)
        data->tempJ = data->sprites.catsD;
    if (data->directionJ == 3)
        data->tempJ = data->sprites.catsU;
}