#include "fdf_bonus.h"

void	change_color(t_data *data)
{
	if (data->way == 0)
		data->color = create_trgb(255, 100, 255, 255);
	else if (data->way == 1)
		data->color = create_trgb(255, 100, 100, 255);
	else if (data->way == 2)
		data->color = create_trgb(255, 255, 100, 255);
	else if (data->way == 3)
		data->color = create_trgb(255, 255, 0, 0);
}

int	find_way(float z, float z1)
{
	if (z < z1)
		return (1);
	else if (z > z1)
		return (2);
	else if (z == z1 && z > 0)
		return (3);
	else
		return (0);
}
