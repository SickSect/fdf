#include "fdf.h"
#include "libft.h"

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

int validate(char *filename)
{
    int fd;
	char *line;


	fd = open (filename, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (-3);
	while (line != NULL)
	{
		validate_sym(line);
		line = get_next_line(fd);
	}
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

	while (i < data->heigth)
	{
		free(data->matrix[i]);
		free(data->color_matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data->color_matrix);
}