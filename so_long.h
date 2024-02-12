/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:57:50 by bcai              #+#    #+#             */
/*   Updated: 2024/02/12 17:22:27 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <stdlib.h>

# define MALLOC_ERROR 1
# define FIRST_LAST_LINE 111
# define MID_LINE 101
# define SIZE 16
/*
typedef struct img_data
{
	void		*img;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}   img_data;*/

enum			e_keycodes
{
	KEY_UP = 126,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	SPACE = 49,
	ESC = 53
};

typedef struct s_sprite
{
	void		*wall;
	void		*cheese;
	void		*mouse_front;
	void		*mouse_back;
	void		*mouse_left;
	void		*mouse_right;
	t_list		*catsr;
	t_list		*catsl;
	t_list		*catsu;
	t_list		*catsd;
	void		*floor;
	void		*door_closed;
	void		*door_open;
	int			width;
	int			height;
}				t_sprite;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_map
{
	int			width;
	int			height;
	int			collectible;
	int			player;
	int			exit;
	int			enemy;
	char		**map;
	int			c_num;
	int			e_num;
}				t_map;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_digit
{
	void		*zero;
	void		*one;
	void		*two;
	void		*three;
	void		*four;
	void		*five;
	void		*six;
	void		*seven;
	void		*eight;
	void		*nine;
	int			width;
	int			height;
}				t_digit;

typedef struct s_data
{
	t_sprite	sprites;
	t_digit		digits;
	t_map		map_data;
	t_mlx		mlxdata;
	t_pos		player_pos;
	t_pos		door_pos;
	t_pos		catb_pos;
	t_pos		catj_pos;
	t_list		*tempb;
	t_list		*tempj;
	int			collected;
	int			moves;
	int			dir_b;
	int			dir_j;
	int	frame_per_moves;
}				t_data;

// utils for map check
void			report_error(char *str, char **map);
void			check_args(int argc, char **argv);
void			height_width(int fd, t_map *map_data);
void			get_map(char *filename, t_map *map_data);
int				wall_check(char *str, int line_indicator);
void			count_ele(t_map *map_data, char *str);
void			handle_map_content(t_map *map_data);
void			flood_fill(t_map *map_data, t_pos *cur, char **md);
char			**map_dup(t_map *map_data);
void			ft_free(char **map_dup);
void			find_pe(t_map *map_data, t_pos *player_pos, t_pos *door_pos);
void			access_check(t_map *map_data, t_pos *player_pos,
					t_pos *door_pos);
void			map_handling(t_map *map_data, char **argv, t_pos *player_pos,
					t_pos *door_pos);

void			render_background(t_data *data);
void			render_other(t_data *data);
void			render_digits(t_data *data);
int				render(t_data *data);
void			init_sprites(t_data *data);
void			init_catu(t_data *data);
void			init_catd(t_data *data);
void			init_catl(t_data *data);
void			init_catr(t_data *data);
void			init_digits(t_data *data);

void			free_digits(t_data *data);
void			free_sprites(t_data *data);
void			free_catsu(t_data *data);
void			free_catsd(t_data *data);
void			free_catsl(t_data *data);
void			free_catsr(t_data *data);

void			game_on(t_data *data);
void			init_data_vars(t_data *data);
void			end_game(t_data *data);
int				key_hook(int keycode, t_data *data);
void			move_up(t_data *data, int keycode);
void			move_down(t_data *data, int keycode);
void			move_left(t_data *data, int keycode);
void			move_right(t_data *data, int keycode);
void			handle_door(t_data *data, int keycode);
void			open_door(t_data *data);

int				cat_on(t_data *data);
void			set_temp(t_data *data);
void			reset_dir_tempb(t_data *data);
void			reset_dir_tempj(t_data *data);
void			catb_non1(t_data *data);
void			handle_door_catb(t_data *data);
void			catj_non1(t_data *data);
void			handle_door_catj(t_data *data);
void			moveup_catb(t_data *data);
void			movedown_catb(t_data *data);
void			moveleft_catb(t_data *data);
void			moveright_catb(t_data *data);
void			moveup_catj(t_data *data);
void			movedown_catj(t_data *data);
void			moveleft_catj(t_data *data);
void			moveright_catj(t_data *data);

void			put_digit1(t_data *data, int digit, int offset);
void			put_digit2(t_data *data, int digit, int offset);
void			put_digit3(t_data *data, int digit, int offset);
void			put_digit4(t_data *data, int digit, int offset);
void			put_digit5(t_data *data, int digit, int offset);
void			display_moves(t_data *data);
void			display_digit(t_data *data);

int				main(int argc, char *argv[]);

#endif
