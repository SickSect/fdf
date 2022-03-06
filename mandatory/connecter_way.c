#include "fdf.h"
#include <math.h>

void	pre_setting(t_cord *cords, t_data *data)
{
	cords->x *= data->zoom;
	cords->x1 *= data->zoom;
	cords->y *= data->zoom;
	cords->y1 *= data->zoom;
}

void	add_move(t_cord *cords, t_data *data)
{
	cords->x += data->mv_x;
	cords->y += data->mv_y;
	cords->x1 += data->mv_x;
	cords->y1 += data->mv_y;
}

int	find_way(float z, float z1)
{
	if (z1 > z && z > 0)
		return (1);
	else if (z == 0 && z1 == 0)
		return (2);
	else if (z > z1 && z >= 0)
		return (3);
	else if (z1 == z && z1 > 0)
		return (4);
	else if (z1 < z && z <= 0)
		return (5);
	else if (z1 == z && z < 0)
		return (6);
    return (0);
}

void	make_matrix(float *x, float *y, float z, t_data *data)
{
	float	iz;

	iz = z * (data->zoom * 0.1);
	*x = *x * cos(data->angle) - *y * sin(data->angle);
	*y = *x * sin(data->angle) + *y * cos(data->angle) - iz;
}
