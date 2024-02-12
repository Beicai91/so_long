#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx/mlx.h"
#include "./libft/libft.h"
#include <stdlib.h>

# define MALLOC_ERROR    1
# define FIRST_LAST_LINE 111
# define MID_LINE 101
# define SIZE 16
/*
typedef struct img_data
{
    void    *img;
    void    *addr;
    int bpp;
    int line_len;
    int endian;
}   img_data;*/

enum    keycodes
{
    KEY_UP = 126,
    KEY_LEFT = 123,
    KEY_RIGHT = 124,
    KEY_DOWN = 125,
    SPACE = 49,
    ESC = 53
};


typedef struct  s_sprite
{
    void    *wall;
    void    *cheese;
    void    *mouse_front;
    void    *mouse_back;
    void    *mouse_left;
    void    *mouse_right;
    t_list    *catsR;
    t_list  *catsL;
    t_list  *catsU;
    t_list  *catsD;
    void    *floor;
    void    *door_closed;
    void    *door_open;
    int width;
    int height;
}   t_sprite;


typedef struct s_mlx
{
    void    *mlx;
    void    *win;
}   t_mlx;

typedef struct  s_map
{
    int width;
    int height;
    int collectible;
    int player;
    int exit;
    int enemy;
    char    **map;
    int c_num;
    int e_num;
}   t_map;

typedef struct  s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct  s_digit
{
    void    *zero;
    void    *one;
    void    *two;
    void    *three;
    void    *four;
    void    *five;
    void    *six;
    void    *seven;
    void    *eight;
    void    *nine;
    int width;
    int height;
}   t_digit;

typedef struct  s_data
{
    t_sprite    sprites;
    t_digit digits;
    t_map   map_data;
    t_mlx   mlxdata;
    t_pos   player_pos;
    t_pos   door_pos;
    t_pos   catB_pos;
    t_pos   catJ_pos;
    t_list  *tempB;
    t_list  *tempJ;
    int collected;
    int moves;
    char    *moves_msg;
    int directionB;
    int directionJ;
}   t_data;

// utils for map check
void    report_error(char *str, char **map);
void check_args(int argc, char **argv);
void    height_width(int fd, t_map *map_data);
void    get_map(char *filename, t_map *map_data);
int wall_check(char *str, int line_indicator);
void    count_ele(t_map *map_data, char *str);
void    handle_map_content(t_map *map_data);
void    flood_fill(t_map *map_data, t_pos *cur, char **md);
char    **map_dup(t_map *map_data);
void    ft_free(char **map_dup);
void    find_PE(t_map *map_data, t_pos *player_pos, t_pos *door_pos);
void    access_check(t_map *map_data, t_pos *player_pos, t_pos *door_pos);
void    map_handling(t_map *map_data, char **argv, t_pos *player_pos, t_pos *door_pos);

void    render_background(t_data *data);
void    render_other(t_data *data);
void    render_digits(t_data *data);
int     render(t_data *data);
void    init_sprites(t_data *data);
void    init_catU(t_data *data);
void    init_catD(t_data *data);
void    init_catL(t_data *data);
void    init_catR(t_data *data);
void    init_digits(t_data *data);

void    free_digits(t_data *data);
void    free_sprites(t_data *data);
void    free_catsU(t_data *data);
void    free_catsD(t_data *data);
void    free_catsL(t_data *data);
void    free_catsR(t_data *data);

void    game_on(t_data *data);
void    end_game(t_data *data);
int    key_hook(int keycode, t_data *data);
void    move_up(t_data *data, int keycode);
void    move_down(t_data *data, int keycode);
void    move_left(t_data *data, int keycode);
void    move_right(t_data *data, int keycode);
void    handle_door(t_data *data, int keycode);
void    open_door(t_data *data);

int cat_on(t_data *data);
void    set_temp(t_data *data);
void    reset_dir_tempB(t_data *data);
void    reset_dir_tempJ(t_data *data);
void    catB_non1(t_data *data);
void    handle_door_catB(t_data *data);
void    catJ_non1(t_data *data);
void    handle_door_catJ(t_data *data);
void    moveup_catB(t_data *data);
void    movedown_catB(t_data *data);
void    moveleft_catB(t_data *data);
void    moveright_catB(t_data *data);
void    moveup_catJ(t_data *data);
void    movedown_catJ(t_data *data);
void    moveleft_catJ(t_data *data);
void    moveright_catJ(t_data *data);

void    put_digit1(t_data *data, int digit, int offset);
void    put_digit2(t_data *data, int digit, int offset);
void    display_digit(t_data *data);

int main(int argc, char *argv[]);

#endif


