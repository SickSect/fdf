#include "fdf.h"

int press(int key, t_data *data)
{
	printf("%d \n", key);
    if(key == 65362)
        data->mv_y -= 10;
    if(key == 65364)
        data->mv_y += 10;
    if(key == 65361)
        data->mv_x -= 10;
    if(key == 65363)
        data->mv_x += 10;
    if (key == 61)
        data->zoom += 10;
    if (key == 45 && data->zoom >= 20)
        data->zoom -= 10;
    if (key == 119)
    {
        
    }  
    else if (key == 115)
    {

    }
    else if (key == 97)
    {

    }
    else if (key == 100)
    {

    }
    mlx_clear_window(data->mlx, data->win);
    mapper(data);

    return (0);
}

int pre_check(char *file, int argc)
{
    int fd;
    if((fd = open(file, O_RDONLY)) == -1)
        return (-1);
    else if(argc > 2)
        return (-2);
    else
        return (0);
}

int main(int argc, char **argv)
{
    int er;

    if((er = pre_check(argv[1], argc)) < 0)
    {
        if(er == -1)
        {
            ft_putstr_fd("No exist file\n", 1);
            return (-1);
        }
        else if(er == -2)
        {
            ft_putstr_fd("More than 1 map", 1);
            return (-1);
        }
    }
    t_data *data;
    data = malloc(sizeof(t_data));
    data->angle_x = 0.8;
    data->angle_y = 0.8;
    data->mv_x = 350;
    data->mv_y = 350;
    fdf_reader(data, argv[1]);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1280, 720, "FRCTL");
    data->zoom = 40;
    mapper(data);
    mlx_hook(data->win, 2, 1L<<0, press, data);
    mlx_loop(data->mlx);
    return (0);
}