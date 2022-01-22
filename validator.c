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
	close(fd);
	if (validate_sym(line) != 0)
		return (-1);
    return (0);
}