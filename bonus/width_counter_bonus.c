#include "fdf_bonus.h"

int width_counter(char *line, char ch)
{
    int i;
    int word;

    i = 0;
    word = 0;
    while(line[i])
    {
        while(line[i] == ch && line[i])
            i++;
        if(line[i] != ch && line[i] && line[i] != '\n')
            word++;
        while(line[i] != ch && line[i])
            i++;
    }
    return (word);
}