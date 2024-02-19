NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -O0
FRAMEWORK = -framework OpenGL -framework AppKit
LIBFT_PATH = ./libft
MINILIBX_PATH = ./minilibx
FT = $(LIBFT_PATH)/libft.a
MLX = $(MINILIBX_PATH)/libmlx.a

SRCS = check_map_access.c \
	   display_digits.c \
	   display_digits_utils.c \
	   utils.c \
	   feedback.c \
	   free_cats.c \
	   free_others.c \
	   game.c \
	   handle_map_content.c \
	   init_cats1.c \
	   init_cats2.c \
	   init_others.c \
	   map.c \
	   movements_catB.c \
	   movements_catB_utils.c \
	   movements_catJ.c \
	   movements_catJ_utils.c \
	   movements_mouse.c \
	   render.c \
	   so_long.c

OBJS = ${SRCS:.c=.o}

all:$(NAME)

$(NAME):$(OBJS) $(FT) $(MLX)
	$(CC) $(CFLAGS) -L $(LIBFT_PATH) -lft -L $(MINILIBX_PATH) -lmlx $(FRAMEWORK) $(OBJS) -o $@

%.o:%.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -I $(MINILIBX_PATH) -c $< -o $@

$(FT):
	make -C $(LIBFT_PATH) all
	make -C $(LIBFT_PATH) bonus

$(MLX):
	make -C $(MINILIBX_PATH) all

clean:
	make -C $(LIBFT_PATH) fclean
	make -C $(MINILIBX_PATH) clean
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re






