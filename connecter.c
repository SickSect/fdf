#include "fdf.h"

#define MX(x, y) (x > y ? x : y);
#define MD(x) ((x > 0) ? x : -x);

void connecter(float x, float y, float x1, float y1, t_data *data)
{
    float step_x;
    float step_y;

    step_x = x1 - x;
    step_y = y1 - y;

}