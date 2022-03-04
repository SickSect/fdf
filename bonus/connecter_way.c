#include "fdf.h"
#include <math.h>

void cycler(t_cord cords, t_data *data)
{
	int	tmp;

	if (cords.x < data->width - 1)
	{
		tmp = data->col;
		connecter(cords, data, 1);
	}
	if (cords.y < data->heigth - 1)
	{
		data->col = tmp;
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

int find_way(float z, float z1)
{
    if (z1 > z && z >= 0)
        return (1);
    else if (z == 0 && z1  == 0)
        return (2);
    else if (z > z1 && z >= 0)
        return (3);
    else if (z1 == z && z1 > 0)
        return (4);
    else if (z1 < z && z <= 0)
		return (5);
	else if (z1 == z && z < 0)
		return (6);
	else if (z > z1 && z < 0)
		return (7);
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
	if (data->fin_map == 0)
	{
    	data->col = get_g(data->color);
		data->tol = get_b(data->color);
	}
}