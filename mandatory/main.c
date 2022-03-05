# include "fdf.h"

int	press(int key, t_data *data)
{
	if ((key >= 65361 && key <= 65364) || key == 61 || key == 45)
		mover(key, data);
	else if (key == 65307)
		exit_graph(data);
	mlx_clear_window(data->mlx, data->win);
	mapper(data);
	return (0);
}

int	pre_check(char *file, int argc)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 0);
		return (-1);
	}
	else if (argc > 2)
		return (-2);
	else
		return (0);
}

int	main_pg(t_data *data)
{
	int	y;

	y = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1360, 1080, "FDF");
	mapper(data);
	mlx_hook(data->win, 2, 1L << 0, press, data);
	mlx_hook(data->win, 17, 1L << 17, destroy_notify, data);
	mlx_string_put(data->mlx, data->win, 10, y + 20,
		create_trgb(255, 255, 255, 255), "MOVE - arrows");
	mlx_string_put(data->mlx, data->win, 10, y + 30,
		create_trgb(255, 255, 255, 255), "ZOOM - + / -");
	mlx_loop(data->mlx);
	return (0);
}

int	set_default(char *filename)
{
	t_data	*data;
	int		er;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd(strerror(errno), 0);
		return (-1);
	}
	er = fdf_reader(data, filename);
	if (er != 0)
	{
		free(data);
		return (-1);
	}
	data->angle = 0.5;
	data->mv_x = 350;
	data->mv_y = 350;
	data->zoom = 20;
	main_pg(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int	er;
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
