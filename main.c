#include "fdf.h"

int press(int key, t_data *data)
{
	printf("%d \n", key);
    
	(void)data;
	return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    t_data *data;

    data = malloc(sizeof(t_data));
    fdf_reader(data, argv[1]);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1280, 720, "FRCTL");
    data->zoom = 40;
    mapper(data);
    mlx_hook(data->win, 2, 1L<<0, press, data);
    mlx_loop(data->mlx);
    return (0);
}