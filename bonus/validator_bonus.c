#include "fdf_bonus.h"
#include "libft.h"

void exit_graph(t_data *data)
{
	map_cleaner(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx,data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data != NULL)
		free(data);
	exit (0);
}

int validate_sym(char *line)
{
	int i;
	int length;

	length = ft_strlen(line);
	i = 0;
	while(line[i] && ((line[i] == ' ' || line[i] == '-') || (line[i] >= '0' && line[i] <= '9')))
		i++;
	if (length != i + 1)
		return (-1);
	return (0);
}


int validate_format(char *line)
{
	while (*line != '\0'  && *line != '.')
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

void map_cleaner(t_data *data)
{
	int i;

	i = 0;
	if (data == NULL)
		return ;
	while (i < data->heigth)
	{
		if (data->matrix[i] != NULL)
			free(data->matrix[i]);
		i++;
	}
	if (data->matrix)
		free(data->matrix);
}