#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct s_cord
{
    float	x;
    float	y;
	float	x1;
	float	y1;
} t_cord;

typedef struct s_data
{
    int		width; 
    int		heigth;
    float	**matrix;
    int     **color_matrix;
    void	*mlx;
    void	*win;
    int     color;
    int     last_color;
    int     way;
    int     zoom;
    int     mv_x;
    int     mv_y;
    float   angle_x;
    float   angle_y;
    int     col;
    int     size_z;
    int     fin_map;
}	t_data;

int width_counter(char *line, char ch);
char	*ft_strnew(size_t size);
int	ft_newline(const char *str);
char	*ft_astrjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int destroy_notify(int key, t_data *data);
int fdf_reader(t_data *data, char *file);
void connecter(t_cord cords, t_data *data, int flg);
void mapper(t_data *data);
int  keyer(int key, t_data *data);
void colorist (t_data *datas);
int get_amount(t_data *data);
int get_trgb(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);
int	create_trgb(int t, int r, int g, int b);
void mover(int key, t_data *data);
int validate(char *filename);
int	get_trgb(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
int color_alloc(t_data *data);
void set_color(int z, t_data *data);
void change_color(t_data *data);
int validate_format(char *filename);
void map_cleaner(t_data *data);
int find_way(float z, float z1);
void add_move(t_cord *cords, t_data *data);
void pre_setting(t_cord *cords, t_data *data);
void pre_color(t_data *data, float x, float y);
void make_matrix(float *x, float *y, float z, t_data *data);
void exit_graph(t_data *data);
float get_float(char *line);
int check_dot(char *line);
void make_cord(t_cord *cords, int flg);
#endif