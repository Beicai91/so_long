#include "so_long.h"

void    init_catU(t_data *data)
{
    t_list  *cat;

    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU1.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU2.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU3.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU4.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU5.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU6.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU7.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catU8.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsU, cat);
}

void    init_catD(t_data *data)
{
    t_list  *cat;

    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD1.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD2.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD3.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD4.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD5.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD6.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD7.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catD8.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsD, cat);
}

void    init_catL(t_data *data)
{
    t_list  *cat;

    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL1.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL2.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL3.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL4.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL5.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL6.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL7.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catL8.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsL, cat);
}

void    init_catR(t_data *data)
{
    t_list  *cat;

    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR1.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR2.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR3.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR4.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR5.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR6.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR7.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
    cat = ft_lstnew(mlx_xpm_file_to_image(data->mlxdata.mlx, "sprites/catR8.xpm", &data->sprites.width, &data->sprites.height));
    ft_lstadd_back(&data->sprites.catsR, cat);
}