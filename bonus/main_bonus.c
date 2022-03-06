#include "fdf_bonus.h"

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
    else if (key == 65307)
        exit_graph(data);
    mlx_clear_window(data->mlx, data->win);
    mapper(data);
    return (0);
}

int pre_check(char *file, int argc)
{
    int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), 0);
		close(fd);
		return (-1);
	}
	else if (argc > 2)
	{
		close(fd);
		return (-2);
	}
    close(fd);
    return (0);
}

int main_pg(t_data *data)
{
    int y;

    y = 0;
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
    er = fdf_reader(data, filename);
    if (er != 0)
        return (-3);
    data->angle_x = 0.1;
    data->angle_y = 0.4;
    data->mv_x = 350;
    data->mv_y = 350;
    data->zoom = 10;
    main_pg(data);
	return (0);
}

int main(int argc, char **argv)
{
    int er;

	er = pre_check(argv[1], argc);
	if (er < 0)
		return (-1);
	er = validate_format(argv[1]);
	if (er < 0)
		return (-1);
	er = set_default(argv[1]);
	if (er != 0)
		return (-1);
	return (0);
}