#include "fdf_bonus.h"

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), 0);
		return (-1);
	}
	line = get_next_line(fd, 1);
	width = width_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	get_heigth(char *file, int len)
{
    char	*line;
    int		fd;
    int		heigth;
	int		cycle;

	cycle = 1;
	heigth = 0;
    fd = open(file, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), 0);
		return (-1);
	}
    while (cycle)
	{
		line = get_next_line(fd, len);
		if (line == NULL)
			cycle = 0;
		heigth++;
		free(line);
	}
	free(line);
	close(fd);
	return (heigth - 1);
}

void	filler(float *data, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while(nums[i])
	{
		if (check_dot(nums[i]) == 0)
		{
			data[i] = ft_atoi(nums[i]);
			free(nums[i]);
		}
		else
		{
			data[i] = get_float(nums[i]);
			free(nums[i]);
		}
		i++;
	}
	free(nums);
}

void	shorter(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), 0);
		return ;
	}
	i = 0;
	line = get_next_line(fd, data->width);
	while (line)
	{
		filler(data->matrix[i], line);
		free(line);
		line = get_next_line(fd, data->width);
		i++;
	}
	data->matrix[i] = NULL;
	free(line);
	close(fd);
}

int	fdf_reader(t_data *data, char *file)
{
	int		i;

	data->width = get_width(file);
	if (data->width == -1)
		return (-1);
	data->heigth = get_heigth(file, data->width);
	if (data->heigth == -1)
		return (-1);
	data->matrix = (float **)malloc(sizeof(float *) * (data->heigth + 1));
	if (!data->matrix)
		return (-3);
	i = 0;
	while (i < data->heigth)
	{
		data->matrix[i++] = malloc(sizeof(float) * (data->width + 1));
		if (!data->matrix[i - 1])
			return (-3);
	}
	shorter(data, file);
	return (0);
}
