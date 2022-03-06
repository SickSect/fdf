#include "fdf_bonus.h"
#include <math.h>

void cycler(t_cord cords, t_data *data)
{   
	if (cords.x < data->width - 1)
	{
		connecter(cords, data, 1);
	}
	if (cords.y < data->heigth - 1)
	{
		connecter(cords, data, 2);
	}
}

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

void make_matrix(float *x, float *y, float z, t_data *data)
{
    float iz;

	iz = z * (data->zoom * 0.1); 
    *x = *x * cos(data->angle_x) + *y * sin(data->angle_x);
    *y = -*x * sin(data->angle_y) + *y * cos(data->angle_y) - iz;
}