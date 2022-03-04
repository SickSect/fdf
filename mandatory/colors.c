#include "fdf.h"

// Color counter count the maximum red pixels
void	change_color(t_data *data)
{
	if (data->way == 1)
		data->color = create_trgb(255, 100, 255, 100);
	else if (data->way == 2)
		data->color = create_trgb(255, 255, 255, 255);
	else if (data->way == 3)
		data->color = create_trgb(255, 100, 255, 100);
	else if (data->way == 4)
		data->color = create_trgb(255, 255, 0, 0);
	else if (data->way == 5)
		data->color = create_trgb(255, 100, 100, 255);
	else if (data->way == 6)
		data->color = create_trgb(255, 0, 0, 255);
}
