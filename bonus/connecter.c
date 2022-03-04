#include "fdf.h"

int	mx(int x, int y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

int	md(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

void mapper(t_data *data)
{
    t_cord	cords;

	cords.y = 0;
	while (cords.y < data->heigth)
	{
		cords.x = 0;
		while (cords.x < data->width)
		{
            cycler(cords, data);
			cords.x++;
		}
		cords.y++;
	}
}

void connecter_cycle(t_cord cords, t_data *data, int ix, int iy)
{
    float pix_x;
    float pix_y;
    int tmp;

    pix_x = cords.x1 - cords.x;
    pix_y = cords.y1 - cords.y;
    tmp = mx(md(pix_x), md(pix_y));
    pix_x /= tmp;
    pix_y /= tmp;
    if (data->fin_map == 0)
        change_color(data);
    else
        data->color = data->color_matrix[iy][ix];
    while((int)(cords.x - cords.x1) || (int)(cords.y - cords.y1))
    {
        mlx_pixel_put(data->mlx, data->win,cords.x, cords.y, data->color);
        cords.x += pix_x;
        cords.y += pix_y;
    }
}

void connecter(t_cord cords, t_data *data, int flg)
{ 
    float z;
    float z1;
    int ix;
    int iy;

    make_cord(&cords, flg);
    ix = (int)cords.x1;
    iy = (int)cords.y1;
    z = data->matrix[(int)cords.y][(int)cords.x];
    z1 = data->matrix[(int)cords.y1][(int)cords.x1];
    if(data->fin_map == 0)
        pre_color(data, cords.x, cords.y);
    pre_setting(&cords, data);
    make_matrix(&cords.x, &cords.y, z, data);
    make_matrix(&cords.x1, &cords.y1, z1, data);
    add_move(&cords, data);
    if (data->fin_map == 0)
        data->way = find_way(z, z1);
    connecter_cycle(cords, data, ix, iy);
    if (data->fin_map == 0)
        data->color_matrix[iy][ix] = data->color;
}