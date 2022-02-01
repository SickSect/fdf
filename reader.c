#include "fdf.h"

int get_width(char *file)
{
	int		fd;
	int 	width;
	char 	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	width = width_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	get_heigth(char *file)
{
    char	*line;
    int		fd;
    int		heigth;
	int		cycle;

	cycle = 1;
	heigth = 0;
    fd = open(file, O_RDONLY, 0);
    while(cycle)
	{
		line = get_next_line(fd);
		if(line == NULL)
			cycle = 0;
		heigth++;
	}
	free(line);
	close(fd);
	return (heigth - 1);
}

void filler(int *data, char *line)
{
	char **nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while(nums[i])
	{
		data[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int fdf_reader(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;

    data->width = get_width(file);
    data->heigth = get_heigth(file);
	data->matrix = (int**)malloc(sizeof(int*) * (data->heigth + 1));
	if (!data->matrix)
		return (-3);
	i = 0;
	while(i < data->heigth)
	{
		data->matrix[i++] = malloc(sizeof(int) * (data->width + 1));
		if(!data->matrix[i - 1])
			return (-3);
	}
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while(line)
	{
		filler(data->matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->matrix[i] = NULL;
	free(line);
	close(fd);
	return (0);
}