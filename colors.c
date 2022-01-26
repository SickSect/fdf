#include "fdf.h"

int color_alloc(t_data *data)
{
	int i;

	i = 0;
	data->color_matrix = (int**)malloc(sizeof(int*) * (data->heigth + 1));
	if (!data->color_matrix)
		return (-3);
	while (i < data->heigth)
	{
		data->color_matrix[i] = malloc(sizeof(int) * (data->width));
		if (!data->color_matrix[i])
			return (-3);
		i++;
	}
	return (0);
}

void set_color(int z, t_data *data)
{
	if (z == 0)
	{
		data->col = 255;
		data->color_matrix[0][0] = create_trgb(255, 255, 255, 255);
	}
	else if (z > 0 && z < 255)
	{	
		data->col = 255 - z;
		data->color_matrix[0][0] = create_trgb(255, 255, 255 - z, 255 - z);
	}
	else if (z > 255)
	{
		data->col = 150;
		data->color_matrix[0][0] = create_trgb (255 ,255, 150, 150);
	}
}

void change_color(t_data *data)
{
	if (data->way == 1)
	{
		data->color = create_trgb(255, 0, 255, 0);
	}
	else if (data->way == 2)
	{
		data->color = create_trgb(255, 255, 255, 255);
	}
	else if (data->way == 3)
	{
		data->color = create_trgb(255, 0, 0, 255);
	}
	else if (data->way == 4)
	{
		data->color = create_trgb(255, 255, 0, 0);
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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