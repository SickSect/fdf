#include "fdf.h"

int keyer(int key, t_data *data)
{
    
    printf("%d", key);
    /*
    if(key == 126)
        data->mv_y -= 10;
    if (key == 125)
        data->mv_y += 10;
    if(key == 123)
        data->mv_x -= 10;
    if (key == 124)
        data->mv_y += 10;
    mlx_clear_window(data->mlx, data->win);
    mapper(data);
    */
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    t_data *data;

    data = malloc(sizeof(t_data));
    fdf_reader(data, argv[1]);
    /*
    i = 0;
    while(i < data->heigth)
    {
        j = 0;
        while(j < data->width)
        {
            printf("%3d ", data->matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    */
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1280, 720, "FRCTL");
    data->zoom = 40;
    mapper(data);
    mlx_key_hook(data->win, keyer, data);
    mlx_loop(data->mlx);
    free(data);
    
}