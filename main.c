#include "fdf.h"

int main(int argc, char **argv)
{
    (void)argc;
    t_data *data;

    data = malloc(sizeof(t_data));
    fdf_reader(data, *argv);
}