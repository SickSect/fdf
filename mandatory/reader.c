#include "fdf.h"


void get_width(int fd, t_data *data)
{
	int flg;
	char reader;

	flg = 1;
	while(flg != -1)
	{
		flg = read(fd, &reader, 1);
		if(flg == 1 && reader != ' ' && reader != '\n' && reader != '\0')
		{
			data->width += 1;
			flg = 2;
		}
		if (reader == '\n' || reader == '\0')
			flg = -1;
		if (reader == ' ' && flg == 2)
		{
			flg = read(fd, &reader, 1);
			if(flg == ' ')
				flg = 2;
			else
				flg = 1;
		}
	}
}

int fdf_reader(t_data *data, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_graph(data);
	get_width(fd, data);
	close(fd);
	exit_graph(data);
	return (0);
}