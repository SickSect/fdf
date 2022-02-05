#include "fdf.h"

#define BASE_H "0123456789ABCDEF"
#define BASE_L "0123456789abcdef"

int check_dot(char *line)
{
    while (*line != ',')
    {
        if (*line == ',')
            return (1);
        line++;
    }
    return (0);
}

int get_index(char word)
{
    int i;

    i = 0;
    while (i < 16)
    {
        if (word == BASE_H[i])
            return (i);
        else if (word == BASE_L[i])
            return (i);
    }
}

int get_pow(int pow)
{
    int step;

    step = 16
    if (pow == 0)
        return (1);
    while (pow != 1)
        step = step * 16
    return (step);
}

int get_dot_part(char *line)
{
    int i;
    int len;
    float ret;
    int pow;

    i = 0;
    ret = 0;
    pow = 5;
    len = ft_strlen(line);
    if (len > 6)
        return (-1); // error too long num
    if (line[i] == '0' && line[i + 1] == 'x')
        i = 2;
    while (line[i])
    {
        ret += get_index(line[i++]) * get_pow(pow--);
    }
    ret *= 0,1;
    return (ret);
}

float get_float(char *line)
{
    char **flt;
    float num;
    float dot_num;

    flt = ft_split(line, ','); // cut 12 | 0xf1231F
    num = ft_atoi(flt[0]);
    dot_num = get_dot_part(flt[1]);
}