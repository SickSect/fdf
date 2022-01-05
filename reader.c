#include "fdf.h"

int get_width(char *file)
{
	int		fd;
	int 	heigth;
	char 	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
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
		{
			cycle = 0;
			free(line);
		}
		heigth++;
	}
	close(fd);
	return (heigth);
}

void fdf_reader(t_data *data, char *file)
{
	int		fd,
	char	*line;
	int		i;

    data->width = get_width(file);
    data->heigth = get_heigth(file);
	data->matrix = malloc(sizeof(int*) * data->heigth + 1);
	i = 0;
	while(i <= data->width)
		data->matrix[i++] = malloc(sizeof(int) * data->width + 1);
}