#include "so_long.h"

void    free_catsU(t_data *data)
{
    t_list  *temp;
    
    while (data->sprites.catsU != NULL)
    {
        temp = data->sprites.catsU;
        data->sprites.catsU = data->sprites.catsU->next;
        free(temp->content);
        free(temp);
    }
}

void    free_catsD(t_data *data)
{
    t_list  *temp;
    
    while (data->sprites.catsD != NULL)
    {
        temp = data->sprites.catsD;
        data->sprites.catsD = data->sprites.catsD->next;
        free(temp->content);
        free(temp);
    }
}

void    free_catsL(t_data *data)
{
    t_list  *temp;
    
    while (data->sprites.catsL != NULL)
    {
        temp = data->sprites.catsL;
        data->sprites.catsL = data->sprites.catsL->next;
        free(temp->content);
        free(temp);
    }
}

void    free_catsR(t_data *data)
{
    t_list  *temp;
    
    while (data->sprites.catsR != NULL)
    {
        temp = data->sprites.catsR;
        data->sprites.catsR = data->sprites.catsR->next;
        free(temp->content);
        free(temp);
    }
}