#include "so_long.h"

void    report_error(char *str, char **map)
{
    int i;

    printf("%s", str);
    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
    exit(0);
}
