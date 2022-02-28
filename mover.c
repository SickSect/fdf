#include "fdf.h"

void mover(int key, t_data *data)
{
    if(key == 65362)
        data->mv_y -= 10;
    else if(key == 65364)
        data->mv_y += 10;
    else if(key == 65361)
        data->mv_x -= 10;
    else if(key == 65363)
        data->mv_x += 10;
    else if (key == 61 && data->zoom <= 120)
        data->zoom += 5;
    else if (key == 45 && data->zoom >= 20)
        data->zoom -= 5;
}