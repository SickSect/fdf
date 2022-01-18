#include "fdf.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void color_change(t_data *data)
{
	if (data->way == 4 || data->way == 3) // high part
		data->color = create_trgb(255, 255, 0, 0);
	else if (data->way == 1 || data->way == 2) // z1 > z
	{
		data->color = create_trgb(255, 255, data->col, data->col);
		if (data->col > 10)
			data->col -= (data->zoom / 5) / 2; // almost rigth
	}
	else if (data->way == 6 || data->way == 5)
	{
		data->color = create_trgb(255, 255, data->col, data->col);
		if (data->col < 250)
			data->col += (data->zoom / 5) / 2; // almost rigth
	}
}