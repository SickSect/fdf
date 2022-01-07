#include "fdf.h"

int keyer(int key, void *data)
{
    (void)data;
    printf("%d", key);
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    t_data *data;
    //int i;
    //int j;


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
    data->win = mlx_new_window(data->mlx, 1000, 1000, "FRCTL");
    data->zoom = 20;
    mapper(data);
    mlx_key_hook(data->win, keyer, NULL);
    mlx_loop(data->mlx);
    free(data);
    
}