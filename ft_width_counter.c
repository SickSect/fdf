#include "libft.h"

int width_counter(char *line, char c)
{
    int i;
    int word;

    i = 0;
    word = 0;
    while(line[i])
    {
        while(line[i] == c && line[i])
            i++;
        if(line[i])
            word++;
        while(line[i] != c && line[i])
            i++;
    }
    return(word);
}