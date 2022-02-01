#include "fdf.h"

int press(int key, t_data *data)
{
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
    set_color(data->matrix[0][0], data);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1280, 720, "FDF");
    mapper(data);
    mlx_hook(data->win, 2, 1L<<0, press, data);
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
    er = fdf_reader(data, filename);
    if (er == -3)
        return (-3);
    er = color_alloc(data);
    if (er == -3)
        return (-3);
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