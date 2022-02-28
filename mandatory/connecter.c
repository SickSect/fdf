#include "fdf.h"

#define MX(x, y) (x > y ? x : y)
#define MD(x) ((x > 0) ? x : -x)


void mapper(t_data *data)
{
    int x;
    int y;
    int tmp;

    y = 0;
    while(y < data->heigth)
    {
        x = 0;
        while(x < data->width)
        {
            if (x < data->width - 1)
			{
                tmp = data->col;
                connecter(x, y, x + 1, y, data); // horiz
			}
            if (y < data->heigth - 1)
			{
                data->col = tmp;
                connecter(x, y, x, y + 1, data); // vertical
			}
            x++;
        }
        y++;
    }
}

void connecter_cycle(float x, float y, float x1, float y1, t_data *data)
{
    float pix_x;
    float pix_y;
    int tmp;
    int flg;
    //printf("|x %f x1 %f|\n", x, x1);
    flg = 0;
    pix_x = x1 - x;
    pix_y = y1 - y;
    tmp = MX(MD(pix_x), MD(pix_y));
    pix_x /= tmp;
    pix_y /= tmp;
    while((int)(x - x1) || (int)(y - y1))
    {
        if (flg == 0)
            change_color(data);
        mlx_pixel_put(data->mlx, data->win,x, y, data->color);
        x += pix_x;
        y += pix_y;
        flg = 1;
    }
}

void connecter(float x, float y, float x1, float y1, t_data *data)
{
    float z;
    float z1;

    z = data->matrix[(int)y][(int)x];
    z1 = data->matrix[(int)y1][(int)x1];
    pre_setting(&x, &y, &x1, &y1, data);
    make_matrix(&x, &y, z, data);
    make_matrix(&x1, &y1, z1, data);
    add_move(&x, &y, &x1, &y1, data);
    data->way = find_way(z, z1);
    connecter_cycle(x, y, x1, y1, data);
}