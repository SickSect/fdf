#include "fdf.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    t_data *data;
    int i;
    int j;


    data = malloc(sizeof(t_data));
    fdf_reader(data, argv[1]);
    
    i = 0;
    while(i < data->heigth)
    {
        j = 0;
        while(j < data->width)
        {
            printf("%d ", data->matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    free(data);
    
}