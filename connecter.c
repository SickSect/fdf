#include "fdf.h"
#include <math.h>

#define MX(x, y) (x > y ? x : y)
#define MD(x) ((x > 0) ? x : -x)

/*
void make_color(t_data *data, float x, float y)
{
    
    if (z1 > z)
        data->color = data->color >> 1;
    else if(z > z1)
        data->color = data->color << 1;
    else if (z1 == z && z > 0)
        return ;
    else
        data->color = 0xffffff;
    
}
*/
void make_matrix(float *x, float *y, float z, t_data *data)
{
   *x = *x * cos(data->angle_x) - *y * sin(data->angle_x);
   *y = *y * cos(data->angle_y) - *x * sin(data->angle_y) - (z * 10);
   (void)x;
   (void)z;
   (void)y;
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

    z = data->matrix[(int)y][(int)x];
    z1 = data->matrix[(int)y1][(int)x1];
    x *= data->zoom;
    x1 *= data->zoom;
    y *= data->zoom;
    y1 *= data->zoom;
    data->color = (z || z1) ? 0xffffff : 0x00ff0000; // k b
    make_matrix(&x, &y, (float)z, data);
    make_matrix(&x1, &y1, (float) z1, data);
    x += data->mv_x;
    y += data->mv_y;
    x1 += data->mv_x;
    y1 += data->mv_y;
    pix_x = x1 - x;
    pix_y = y1 - y;
    tmp = MX(MD(pix_x), MD(pix_y));
    pix_x /= tmp;
    pix_y /= tmp;
    while((int)(x - x1) || (int)(y - y1))
    {
        //make_color(data, z, z1);
        mlx_pixel_put(data->mlx, data->win,x, y, data->color);
        x += pix_x;
        y += pix_y;
    }
}
