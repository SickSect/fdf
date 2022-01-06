#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

typedef struct s_data
{
    int		width;
    int		heigth;
    int		**matrix;
    void	*mlx;
    void	*win;
}	t_data;

void fdf_reader(t_data *data, char *file);
#endif