#include "fdf.h"
#include <math.h>

void pre_setting(float *x, float *y, float *x1, float *y1, t_data *data)
{
    *x *= data->zoom;
    *x1 *= data->zoom;
    *y *= data->zoom;
    *y1 *= data->zoom;
}

void add_move(float *x, float *y, float *x1, float *y1, t_data *data)
{
    *x += data->mv_x;
    *y += data->mv_y;
    *x1 += data->mv_x;
    *y1 += data->mv_y;
}

int find_way(int z, int z1)
{
    if (z1 > z)
        return (1);
    else if (z == 0 && z1  == 0)
        return (2);
    else if (z > z1)
        return (3);
    else if (z1 == z)
        return (4);
    return (0);
}

void make_matrix(float *x, float *y, float z, t_data *data)
{
    *x = *x * cos(data->angle_x) + *y * sin(data->angle_x);
    //MAKE TRIGGER ON Z BC IT DEPENDS ON Z
    //z = *y * sin(data->angle_x) + z * cos(data->angle_y);
    *y = -*x * sin(data->angle_y) + *y * cos(data->angle_y) - (z * data->size_z);
    //printf("Y = %f\n", *y);
}

void pre_color(t_data *data, int x, int y)
{
    data->color = data->color_matrix[(int)y][(int)x];
    data->col = get_g(data->color);
}