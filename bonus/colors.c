#include "fdf.h"

void change_color(t_data *data)
{
	if (data->way == 0)
		data->color = create_trgb(255, 255, 255, 255);
	else if (data->way == 1)
	{
		data->color = create_trgb(255, data->col, 0, 200);
        if( data->col < 250)
            data->col += 25;
        ft_putnbr_fd(data->col, 1);
        ft_putchar_fd('\n', 1);
	}
	else if (data->way == 2)
	{
		data->color = create_trgb(255, 0, 255, 0);
	}
	else if (data->way == 3)
	{
		data->color = create_trgb(255, 0, 0, 255);
	}
}

int find_way(float z, float z1)
{
    if (z >= 0 && z1 >= 0)
    {
        if (z < z1)
            return (1);
        else if (z == z1)
            return (2);
        else
            return (3);
    }
    else if (z == 0 && z1 == 0)
        return (0);
    else
    {
        if (z < z1)
            return (4);
        else if (z == z1)
            return (5);
        else
            return (6);
    }
}

