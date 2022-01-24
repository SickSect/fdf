#include "fdf.h"

int color_alloc(t_data *data)
{
	int i;

	i = 0;
	data->color_matrix = (int*)malloc(sizeof(int*) * (data->heigth + 1));
	if (!data->color_matrix)
		return (-3);
	while (i < data->heigth)
	{
		data->color_matrix[i] = malloc(sizeof(int) * (data->width));
		if (!data->color_matrix[i])
			return (-3);
		data->color_matrix[i] = -1;
	}
}

void set_color(int x, int y, int z, int color)
{
	if (color == -1) // if no color
	{
		if (z == 0)
			data->color_matrix[y][x] = create_trgb(255, 255, 255, 255);
		else if (z > 0 && z < 255)
			data->color_matrix[y][x] = create_trgb(255, 255, 255 - z, 255 - z);
		else if (z > 255)
			data->color_matrix[y][x] = create_trgb (255 ,255, 200, 200);
	}
	else if (color == -2) // if have color
		data->color_matrix[y][x] = color;
	else if (color  != -1 && color != -2) // make last color
		data->last_color = color;
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