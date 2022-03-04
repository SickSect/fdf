#include "fdf.h"
#include <math.h>

void pre_setting(t_cord *cords, t_data *data)
{
    cords->x *= data->zoom;
    cords->x1 *= data->zoom;
    cords->y *= data->zoom;
    cords->y1 *= data->zoom;
}

void add_move(t_cord *cords, t_data *data)
{
    cords->x += data->mv_x;
    cords->y += data->mv_y;
    cords->x1 += data->mv_x;
    cords->y1 += data->mv_y;
}

int find_way(float z, float z1)
{
    if (z1 > z)
        return (1);
    else if (z == 0 && z1  == 0)
        return (2);
    else if (z > z1)
        return (3);
    else if (z1 == z && z1 > 0)
        return (4);
    return (0);
}

void make_matrix(float *x, float *y, float z, t_data *data)
{
    *x = *x * cos(data->angle_x) + *y * sin(data->angle_x);
    *y = -*x * sin(data->angle_y) + *y * cos(data->angle_y) - (z * data->size_z);
}

void pre_color(t_data *data, float x, float y)
{
    data->color = data->color_matrix[(int)y][(int)x];
    data->col = get_g(data->color);
}