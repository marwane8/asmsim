#include <stdio.h>
#include <stdlib.h>
#include "asim.h"


int gline(char l[], FILE *fp);

int main(int argc, char *argv[])
{

    FILE *fp;
    char line[MAXLEN];

    if (argc != 2)
    {
        printf("\nUsage: asim <file.asm>\n\n\n");
        return 0;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("asim file error");
        exit(EXIT_FAILURE);
    }

    while (gline(line, fp) >= 0) {
        process_line(line);
    }
        process_line(line);
}

int gline(char ln[], FILE *fp)
{
    int c = 0, i = 0;
    while ((c = getc(fp)) != EOF && c != '\n' && i < MAXLEN - 1)
    {
        ln[i] = c;
        i++;
    }
    ln[i] = '\0';

    if (c == EOF)
    {
        return -1;
    };

    return 0;
}