#include "fdf.h"

void mover(int key, t_data *data)
{
    if(key == 65362)
        data->mv_y -= 10;
    else if(key == 65364)
        data->mv_y += 10;
    else if(key == 65361)
        data->mv_x -= 10;
    else if(key == 65363)
        data->mv_x += 10;
    else if (key == 61 && data->zoom <= 120)
        data->zoom += 5;
    else if (key == 45 && data->zoom >= 20)
        data->zoom -= 5;
}

int destroy_notify(int key, t_data *data)
{
    (void)key;
    exit_graph(data);
    return (0);
}

void	make_cord(t_cord *cords, int flg)
{
	if (flg == 1)
	{
		cords->x1 = cords->x + 1;
		cords->y1 = cords->y;
	}
	else if (flg == 2)
	{
		cords->x1 = cords->x;
		cords->y1 = cords->y + 1;
	}
}