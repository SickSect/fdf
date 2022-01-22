#include "fdf.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void color_change(t_data *data)
{
	if (data->way == 4 || data->way == 3) // high part
	{
		if (data->last_color == -1)
			data->color = create_trgb(255, 255, 0, 0);
		else if (data->last_color >= 0)
			data->color = data->last_color;
	}
	else if (data->way == 1 || data->way == 2) // z1 > z
	{
		data->color = create_trgb(255, 255, data->col, data->col);
		if (data->col > 10)
			data->col -= (data->zoom / 5) / 2;
	}
	else if (data->way == 6 || data->way == 5)
	{
		data->color = create_trgb(255, 255, data->col, data->col);
		if (data->col < 250)
			data->col += (data->zoom / 5) / 2;
	}
	data->last_color = data->color;
}

int	get_trgb(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}