# include "fdf.h"

#define BASE_SYM "0123456789ABCDEFabcdef0x "

void	exit_graph(t_data *data)
{
	map_cleaner(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data != NULL)
		free(data);
	exit (0);
}

int	validate_format(char *line)
{
	while (*line != '\0' && *line != '.')
		line++;
	if (*line != '.')
		return (-1);
	line++;
	if (*line == 'f')
		line++;
	else
		return (-2);
	if (*line == 'd')
		line++;
	else
		return (-2);
	if (*line == 'f')
		line++;
	else
		return (-2);
	return (0);
}

void	map_cleaner(t_data *data)
{
	int	i;

	i = 0;
	if (data == NULL)
		return ;
	while (i < data->heigth)
	{
		if (data->matrix[i])
			free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}
