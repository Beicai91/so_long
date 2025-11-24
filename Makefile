NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -O0
FRAMEWORK = -framework OpenGL -framework AppKit
LIBFT_PATH = ./lib/libft
MINILIBX_PATH = ./lib/minilibx
FT = $(LIBFT_PATH)/libft.a
MLX = $(MINILIBX_PATH)/libmlx.a

SRCS = src/check_map_access.c \
	   src/display_digits.c \
	   src/display_digits_utils.c \
	   src/utils.c \
	   src/feedback.c \
	   src/free_cats.c \
	   src/free_others.c \
	   src/game.c \
	   src/handle_map_content.c \
	   src/init_cats1.c \
	   src/init_cats2.c \
	   src/init_others.c \
	   src/map.c \
	   src/movements_catB.c \
	   src/movements_catB_utils.c \
	   src/movements_catJ.c \
	   src/movements_catJ_utils.c \
	   src/movements_mouse.c \
	   src/render.c \
	   src/main.c

OBJS = ${SRCS:.c=.o}

all:$(NAME)

$(NAME):$(OBJS) $(FT) $(MLX)
	$(CC) $(CFLAGS) -L $(LIBFT_PATH) -lft -L $(MINILIBX_PATH) -lmlx $(FRAMEWORK) $(OBJS) -o $@

%.o:%.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -I $(MINILIBX_PATH) -I ./include -c $< -o $@

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






