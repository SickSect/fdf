#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <error.h>
#include <string.h>

typedef struct s_data
{
    int		width;
    int		heigth;
    int		**matrix;
    void	*mlx;
    void	*win;
    int     color;
    int     zoom;
    int     mv_x;
    int     mv_y;
    float   angle_x;
    float   angle_y;
}	t_data;

void fdf_reader(t_data *data, char *file);
void connecter(float x, float y, float x1, float y1, t_data *data);
void mapper(t_data *data);
int  keyer(int key, t_data *data);
#endif