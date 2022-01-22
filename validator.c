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
	int len_l;
	int len_p;

	fd = open (filename, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	while(line != NULL)
	{
		if (validate_sym(line) != 0)
			return (-1);
		len_p = width_counter(line, ' ');
		line = get_next_line(fd);
		if (line != NULL)
		{
			len_l = width_counter(line, ' ');
			if (len_p != len_l)
				return (-1);
		}
	}
    return (0);
}