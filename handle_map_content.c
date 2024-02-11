
#include "so_long.h"

int wall_check(char *str, int line_indicator)
{
    int i;

    i = 0;
    if (line_indicator == FIRST_LAST_LINE)
    {
        while (str[i] != '\0')
        {
            if (str[i] != '1')
                return (1);
            i++;
        }
    }
    else if (line_indicator == MID_LINE)
    {
        if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
            return (1);
    }
    return (0);
}

void    count_ele(t_map *map_data, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 'P')
            map_data->player++;
        if (str[i] == 'C')
            map_data->collectible++;
        if (str[i] == 'E')
            map_data->exit++;
        i++;
    }
}

void    handle_map_content(t_map *map_data)
{
    int i;
    if (wall_check(map_data->map[0], FIRST_LAST_LINE) == 1 || wall_check(map_data->map[map_data->height - 1], FIRST_LAST_LINE) == 1)
        report_error("Error\nMap is not surrounded by walls\n", map_data->map);
    i = 1;
    while (i < map_data->height - 1)
    {
        if (wall_check(map_data->map[i++], MID_LINE) == 1)
            report_error("Error\nMap is not surrounded by walls\n", map_data->map);
    }
    i = 0;
    while (i < map_data->height)
        count_ele(map_data, map_data->map[i++]);
    if (map_data->player != 1 || map_data->collectible < 1 || map_data->exit != 1)
        report_error("Error\nLack of game elements to play\n", map_data->map);
}
