#include "fdf.h"

#define BASE_H "0123456789ABCDEF"
#define BASE_L "0123456789abcdef"

int check_dot(char *line)
{
    //printf("FIND\n");
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == ',')
            return (1);
        i++;
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
        i++;
    }
    return (-1);
}

int get_pow(int pow)
{
    int step;

    step = 16;
    if (pow == 0)
        return (1);
    while (pow != 1)
    {
        step *= step;
        pow--;
    }
    return (step);
}

float get_dot_part(char *line)
{
    int i;
    float ret;
    int len;
    int pow;

    ret = 0.0;
    i = 0;
    len = ft_strlen(line);
    if (line[i] == '0' && line [i + 1] == 'x')
        i += 2;
    pow = len - i - 1;
    while (i < len)
    {
        ret += get_index(line[i]) * get_pow(pow);
        i++;
        pow--;
    }
    printf("FLOAT HERE - %f\n", ret);
    while (ret > 1)
        ret *= 0.1;
    printf("FLOAT HERE - %f\n", ret);
    return (ret);
}

float get_float(char *line)
{
    printf(" HERE line is - %s \n", line);
    char **flt;
    int num;
    float dot_num;

    flt = ft_split(line, ','); // cut 12 | 0xf1231F
    printf ("after split 1 - %s  2 - %s\n", flt[0], flt[1]);
    num = ft_atoi(flt[0]);
    printf("INT IS %d\n", num);
    dot_num = num + get_dot_part(flt[1]);
    printf("FLOAT FIN %f\n", dot_num);
    return (dot_num);
}