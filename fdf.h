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
    int     color; // main color
    int     zoom; //zome and moves
    int     mv_x;
    int     mv_y;
    float   angle_x; // angles for rotate
    float   angle_y;
    int     way; // in what way should ba colored
    int     col; // 0 - 256 of each TRGB
    int     size_z; // variable to + - z data
}	t_data;

void fdf_reader(t_data *data, char *file);
void connecter(float x, float y, float x1, float y1, t_data *data);
void mapper(t_data *data);
int  keyer(int key, t_data *data);
void color_change(t_data *datas);
int get_amount(t_data *data);
int get_trgb(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);
int	create_trgb(int t, int r, int g, int b);
void mover(int key, t_data *data);
#endif