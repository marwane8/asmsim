#include <stdio.h>
#include "asim.h"

#define BUFFSIZE 3

int process_line(char l[MAXLEN])
{
    char wbuff[BUFFSIZE][MAXWORD] = {0};
    int w = 0, i = 0, c = 0;

    while (l[i] != '\0' && i < MAXLEN && w < BUFFSIZE)
    {
        // printf("char: %i~ w: %i~ c: %i~i: %i\n", l[i], w, c, i);
        if (l[i] == ',')
        {
            i++;
            continue;
        }
        if (l[i] == ' ')
        {
            wbuff[w][c] = '\0';
            c = 0;
            w++;
            i++;
            continue;
        }

        wbuff[w][c] = l[i];

        c++;
        i++;
    }
    log_buff(wbuff);

    return 0;
}

void log_buff(char b[][MAXWORD])
{

    printf("=> buffer:\n\t[");
    for (int i = 0; i < BUFFSIZE; i++)
    {
        printf("%i:%s ", i, b[i]);
        
    }
    printf("]\n=> end\n");
}