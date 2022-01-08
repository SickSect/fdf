#include "fdf.h"

#define MX(x, y) (x > y ? x : y)
#define MD(x) ((x > 0) ? x : -x)

void make_matrix(float *x, float *y, float *z)
{

}

void mapper(t_data *data)
{
    int x;
    int y;

    y = 0;
    while(y < data->heigth)
    {
        x = 0;
        while(x < data->width)
        {
            if (x < data->width - 1)
                connecter(x, y, x + 1, y, data); // horiz
            if (y < data->heigth - 1)
                connecter(x, y, x, y + 1, data); // vertical
            x++;
        }
        y++;
    }
}

void connecter(float x, float y, float x1, float y1, t_data *data)
{
    float pix_x;
    float pix_y;
    int tmp;
    int z;
    int z1;
    (void)z1;

    z = data->matrix[(int)y][(int)x];
    z1 = data->matrix[(int)y1][(int)x1];
    x *= data->zoom;
    x1 *= data->zoom;
    y *= data->zoom;
    y1 *= data->zoom;
    data->color = (z) ? 0xe80c0c : 0xffffff;
    pix_x = x1 - x;
    pix_y = y1 - y;
    tmp = MX(MD(pix_x), MD(pix_y));
    pix_x /= tmp;
    pix_y /= tmp;

    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx, data->win,x, y, data->color);
        x += pix_x;
        y += pix_y;
    }
}
