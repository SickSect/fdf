#include "fdf.h"
#include <math.h>

#define MX(x, y) (x > y ? x : y)
#define MD(x) ((x > 0) ? x : -x)


void make_matrix(float *x, float *y, float z, t_data *data)
{
    *x = *x * cos(data->angle_x) - *y * sin(data->angle_x);
    *y = *x * sin(data->angle_y) + *y * cos(data->angle_y) - (z * data->size_z);
}

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
    
    pix_x = x1 - x;
    pix_y = y1 - y;
    tmp = MX(MD(pix_x), MD(pix_y));
    pix_x /= tmp;
    pix_y /= tmp;
    while((int)(x - x1) || (int)(y - y1))
    {
        change_color(data);
        mlx_pixel_put(data->mlx, data->win,x, y, data->color);
        x += pix_x;
        y += pix_y;
    }
}

void connecter(float x, float y, float x1, float y1, t_data *data)
{
    int z;
    int z1;
    int ix;
    int iy;

    ix = (int)x1;
    iy = (int)y1;
    z = data->matrix[(int)y][(int)x];
    z1 = data->matrix[(int)y1][(int)x1];
    data->color = data->color_matrix[(int)y][(int)x];
    data->col = get_g(data->color);

    x *= data->zoom;
    x1 *= data->zoom;
    y *= data->zoom;
    y1 *= data->zoom;
    make_matrix(&x, &y, (float)z, data);
    make_matrix(&x1, &y1, (float) z1, data);
    x += data->mv_x;
    y += data->mv_y;
    x1 += data->mv_x;
    y1 += data->mv_y;
    
    if (z1 > z)
       data->way = 1;
    else if (z == 0 && z1  == 0)
        data->way = 2;
    else if (z > z1)
        data->way = 3;
    else if (z1 == z)
        data->way = 4;
    connecter_cycle(x, y, x1, y1, data);
    data->color_matrix[iy][ix] = data->color;
}