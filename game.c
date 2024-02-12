#include "so_long.h"

void    end_game(t_data *data)
{
    int i;

    i = -1;
    while (data->map_data.map[++i] != NULL)
        free(data->map_data.map[i]);
    free_digits(data);
    free_sprites(data);
    free_catsU(data);
    free_catsD(data);
    free_catsL(data);
    free_catsR(data);
    mlx_destroy_window(data->mlxdata.mlx, data->mlxdata.win);
    //mlx_destroy_display(data->mlxdata.mlx);
    free(data->mlxdata.mlx);
    exit(0);
}


int    key_hook(int keycode, t_data *data)
{
    if (keycode == KEY_UP)
    {
        move_up(data, keycode);
        data->moves++;
        display_digit(data);
        //data->moves_msg = ft_itoa(data->moves);
        //mlx_string_put(data->mlxdata.mlx, data->mlxdata.win, data->map_data.width / 2 * SIZE, (data->map_data.height + 2) * SIZE, 0x00FFFFFF, data->moves_msg);
    }
    if (keycode == KEY_DOWN)
    {
        move_down(data, keycode);
        data->moves++;
        display_digit(data);
    }
    if (keycode == KEY_LEFT)
    {
        move_left(data, keycode);
        data->moves++;
        display_digit(data);
    }
    if (keycode == KEY_RIGHT)
    {
        move_right(data, keycode);
        data->moves++;
        display_digit(data);
    }
    if (keycode == ESC || keycode == SPACE)
        end_game(data);
    return (0);
}

int cat_on(t_data *data)
{
    if (data->moves != 0)
    {
        if (data->directionB == 0)
            moveup_catB(data);
        if (data->directionB == 1)
            movedown_catB(data);
        if (data->directionB == 2)
            moveleft_catB(data);
        if (data->directionB == 3)
            moveright_catB(data);
        if (data->directionJ == 0)
            moveright_catJ(data);
        if (data->directionJ == 1)
            moveleft_catJ(data);
        if (data->directionJ == 2)
            movedown_catJ(data);
        if (data->directionJ == 3)
            moveup_catJ(data);
    }
    return (0);
}

void    set_temp(t_data *data)
{
    if (data->directionB == 0)
        data->tempB = data->sprites.catsU;
    if (data->directionB == 1)
        data->tempB = data->sprites.catsD;
    if (data->directionB == 2)
        data->tempB = data->sprites.catsL;
    if (data->directionB == 3)
        data->tempB = data->sprites.catsR;
    if (data->directionJ == 0)
        data->tempJ = data->sprites.catsR;
    if (data->directionJ == 1)
        data->tempJ = data->sprites.catsL;
    if (data->directionJ == 2)
        data->tempJ = data->sprites.catsD;
    if (data->directionJ == 3)
        data->tempJ = data->sprites.catsU;
}

void    game_on(t_data *data)
{
    data->collected = 0;
    data->moves = 0;
    data->sprites.catsU = NULL;
    data->sprites.catsD = NULL;
    data->sprites.catsL = NULL;
    data->sprites.catsR = NULL;
    data->directionB = rand() % 4;
    data->directionJ = rand() % 4;
    data->mlxdata.mlx = mlx_init();
    if (!(data->mlxdata.mlx))
        return ;
    data->mlxdata.win = mlx_new_window(data->mlxdata.mlx, SIZE * data->map_data.width, SIZE * (data->map_data.height + 5), "Cheese Station N");
    if (!data->mlxdata.win)
    {
        //mlx_destroy_display(data->mlxdata.mlx);
        free(data->mlxdata.mlx);
        return ;
    }
    render(data);
    set_temp(data);
    mlx_loop_hook(data->mlxdata.mlx, cat_on, data);
    mlx_key_hook(data->mlxdata.win, key_hook, data);
    mlx_loop(data->mlxdata.mlx);
    mlx_destroy_window(data->mlxdata.mlx, data->mlxdata.win);
    //mlx_destroy_display(data->mlxdata.mlx);
    free(data->mlxdata.mlx);
    free(data->moves_msg);
}
