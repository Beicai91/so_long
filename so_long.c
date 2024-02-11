#include "so_long.h"
/*static void my_mlx_pixel_put(img_data *image, int x, int y, int color)
{
    char    *pixel_position;

    pixel_position = image->addr + (y * image->line_len + x * (image->bpp / 8));
    *(unsigned int *)pixel_position = color;
}

static void draw_square(img_data *image, int x, int y, int size, int color)
{
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
            my_mlx_pixel_put(image, j, i, color);
    }
}*/

void check_args(int argc, char **argv)
{
    int i;

    if (argc != 2)
        report_error("Error\nArguments have to be two!\n", NULL);
    i = 0;
    while (argv[1][i] && argv[1][i] != '.')
        i++;
    if (ft_strnstr(&argv[1][i], ".ber", 4) == NULL || ft_strlen(argv[1]) - i != 4)
        report_error("Error\nFile format should be \".ber\"\n", NULL);
}


int main(int argc, char *argv[])
{
    t_data   data;

    check_args(argc, argv);
    map_handling(&(data.map_data), argv, &(data.player_pos), &(data.door_pos));
    game_on(&data);
    
    //add game_over function to destroy image, window etc then exit
    /*
    mlx_data    mlx_var;
    img_data    image;

    mlx_var.mlx = mlx_init();
    if (!(mlx_var.mlx))
        return (MALLOC_ERROR);
    mlx_var.win = mlx_new_window(mlx_var.mlx, 1920, 1080, "So long!");
    if (!(mlx_var.win))
    {
        mlx_destroy_display(mlx_var.mlx);
        free(mlx_var.mlx);
        return (MALLOC_ERROR);
    }
    image.img = mlx_new_image(mlx_var.mlx, 1920, 1080);
    image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_len, &image.endian);
    draw_square(&image, 5, 5, 10, 0x00FF0000);
    mlx_put_image_to_window(mlx_var.mlx, mlx_var.win, image.img, 0, 0);
    mlx_loop(mlx_var.mlx);
    mlx_destroy_window(mlx_var.mlx, mlx_var.win);
    mlx_destroy_display(mlx_var.mlx);
    free(mlx_var.mlx);
    */
}
