#include "fdf.h"

int press(int key, t_data *data)
{
    //printf("%d\n", key);
    if ((key >= 65361 && key <= 65364) || key == 61 || key == 45)
        mover(key, data);
    else if (key == 119)
        data->angle_y += 0.1;
    else if (key == 115)
        data->angle_y -= 0.1;
    else if (key == 100)
        data->angle_x -= 0.1;
    else if (key == 97)
        data->angle_x += 0.1;
    else if (key == 122)
        data->size_z += 1;
    else if (key == 120 && data->size_z != 1)
        data->size_z -= 1;
    else if (key == 65307)
        exit_graph(data);
    mlx_clear_window(data->mlx, data->win);
    mapper(data);
    data->fin_map = 1;
    return (0);
}

int pre_check(char *file, int argc)
{
    int fd;
    if((fd = open(file, O_RDWR)) == -1)
        return (-1);
    else if(argc > 2)
        return (-2);
    else
        return (0);
}

int main_pg(t_data *data)
{
    int y;

    y = 0;
    set_color(data->matrix[0][0], data);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1360, 1080, "FDF");
    mapper(data);
    mlx_hook(data->win, 2, 1L<<0, press, data);
    mlx_hook(data->win, 17, 1L<<17, destroy_notify, data);
    mlx_string_put(data->mlx, data->win, 10, y + 20,create_trgb(255, 255, 255, 255), "MOVE - arrows");
    mlx_string_put(data->mlx, data->win, 10, y + 30,create_trgb(255, 255, 255, 255), "ZOOM - + / -");
    mlx_string_put(data->mlx, data->win, 10, y + 40,create_trgb(255, 255, 255, 255), "MULTIPLY Z - z / x");
    mlx_string_put(data->mlx, data->win, 10, y + 50,create_trgb(255, 255, 255, 255), "ROTATE- w/s/a/d");
    mlx_loop(data->mlx);
    return (0);
}

int set_default(char *filename)
{
    t_data *data;
    int er;
    
    data = malloc(sizeof(t_data));
    if (!data)
        return (-3);
    data->angle_x = 0.1;
    data->angle_y = 0.1;
    data->mv_x = 350;
    data->mv_y = 350;
    data->size_z = 1;
    data->zoom = 40;
    data->fin_map = 0;
    data->last_color = 0;
    er = fdf_reader(data, filename);
    if (er == -3)
        return (-1);
    er = color_alloc(data);
    if (er == -3)
        return (-1);
    main_pg(data);
	return (0);
}

int main(int argc, char **argv)
{
    int er;

    if ((er = pre_check(argv[1], argc)) < 0)
    {
        if(er == -1)
            ft_putstr_fd("No exist file\n", 1);
        else if(er == -2)
            ft_putstr_fd("More than 1 file\n", 1);
        return (-1);
    }
    if ((er = validate_format(argv[1])) < 0)
    {
        if (er == -1)
            ft_putstr_fd("File does not have format\n", 1);
        else if (er == -2)
            ft_putstr_fd("Wrong files format\n", 1);
        return (-1);
    }
	if ((er = set_default(argv[1])) != 0)
	{
		ft_putstr_fd("Memory is full\n", 1);
		return (-1);
	}
    return (0);
}