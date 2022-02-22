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
		data->color_matrix[0][0] = create_trgb(255, 255, 255, 255);
	}
	else if (z > 0 && z < 255)
	{	
		data->color_matrix[0][0] = create_trgb(255, 255, 150, 150);
	}
	else if (z > 255)
	{
		data->color_matrix[0][0] = create_trgb (255 ,255, 150, 150);
	}
}

// Color counter count the maximum red pixels
void change_color(t_data *data)
{
	if (data->way == 1)
	{
		if (data->col > 4)
		{
			data->col -= 24;	//12 - (data->zoom / 10) + 1;
		}
		data->color = create_trgb(255, 255, data->col, data->col);
	}
	else if (data->way == 2)
		data->color = create_trgb(255, 255, 255, 255);
	else if (data->way == 3)
	{
		if (data->col < 254) // 254!!
			data->col += 24;	//12 - (data->zoom / 10) + 1;
		data->color = create_trgb(255, 255, data->col, data->col);
	}
	else if (data->way == 4)
		data->color = create_trgb(255, 255, data->col, data->col);
	
}

