#include "fdf.h"

char *join(char *before, char sym)
{
	int i;
	char *after;

	i = 0;
	if (!before)
	{
		before = malloc(sizeof(char) * 2);
		before[1] = '\0';
		before[0] = sym;
		return (before);
	}
	if (!before)
		return (NULL);
	after = malloc(sizeof(char) * (ft_strlen(before) + 2));
	while(before[i])
	{
		after[i] = before[i];
		i++;
	}

	free(before);
	return (after);
}

int get_width(char *file)
{
	int width;
	int fd;
	int byte;
	char reader;

	fd = open(file, O_RDONLY);
	byte = 1;
	width = 0;
	while(byte)
	{
		byte = read(fd, &reader, 1);
		if(reader != ' ' && reader != '\n' && reader != '\0')
		{
			width++;
			//!!!!!!! reading
		}
		else if (reader == ' ')
			byte = read(fd, &reader, 1);
		else
			byte = -1;
	}
	return (width);
}

int fdf_reader(t_data *data, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_graph(data);
	close(fd);
	data->width = get_width(file);
	printf("WIDTH %d\n", data->width);
	exit_graph(data);
	return (0);
}