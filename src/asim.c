#include <string.h>
#include <stdio.h>
#include "asim.h"

#define BUFFSIZE 3
char REG[8][4] = {
    {"al"},
    {"cl"},
    {"dl"},
    {"bl"},
    {"ah"},
    {"ch"},
    {"dh"},
    {"bh"}};

char W_REG[8][4] = {
    {"ax"},
    {"cx"},
    {"dx"},
    {"bx"},
    {"sp"},
    {"bp"},
    {"si"},
    {"di"}

};

int fill_buff(char ln[MAXLEN], char buff[][MAXWORD]);

int buff2bin(char buff[MAXLEN][MAXWORD], int *bb);
int get_op(char *op, int *op_code);
int get_addr(char *addr_code, int *reg, int *w, int *addr_type);

int process_line(char l[MAXLEN])
{

    int bin_code = 0;

    char wbuff[BUFFSIZE][MAXWORD] = {0};
    fill_buff(l, wbuff);
    log_buff(wbuff);
    buff2bin(wbuff, &bin_code);
    printf("\ncode: %0x \n\n", bin_code);

    return 0;
}

int fill_buff(char ln[MAXLEN], char buff[][MAXWORD])
{
    int w = 0, i = 0, c = 0;

    while (ln[i] != '\0' && i < MAXLEN && w < BUFFSIZE)
    {
        // printf("char: %i~ w: %i~ c: %i~i: %i\n", l[i], w, c, i);
        if (ln[i] == ',')
        {
            i++;
            continue;
        }
        if (ln[i] == ' ')
        {
            buff[w][c] = '\0';
            c = 0;
            w++;
            i++;
            continue;
        }

        buff[w][c] = ln[i];

        c++;
        i++;
    }
    return 0;
}

int buff2bin(char buff[MAXLEN][MAXWORD], int *bb)
{

    char *w_op = buff[0];
    char *w_1 = buff[1];
    char *w_2 = buff[2];

    int op = 0, w = 0, mod = 0, reg = 0, rm = 0;
    int addr1_type = 0, addr2_type = 0;

    get_op(w_op, &op);
    get_addr(w_1, &reg, &w, &addr1_type);
    get_addr(w_2, &rm, &w, &addr2_type);

    printf("op: %i, w: %i, mod: %i, reg: %i, rm: %i | typ1: %i, typ2: %i", op, w, mod, reg, rm, addr1_type, addr2_type);
    return 0;
}

int get_op(char *op, int *op_code)
{

    if (0 == strncmp(op, "mov", MAXWORD))
    {
        *op_code = 136;
        return 0;
    }

    return -1;
}

int get_addr(char *addr_code, int *reg, int *w, int *addr_type)
{
    for (int i = 0; i < ADDRSIZE; i++)
    {
        // printf("addr: %s, reg: %s, wreg: %s, \n", addr_code, REG[i], W_REG[i]);
        if (0 == strncmp(addr_code, REG[i], MAXWORD))
        {
            *reg = i;
            *w = 0;
            *addr_type = REGSTR;
            return 0;
        }

        else if (0 == strncmp(addr_code, W_REG[i], MAXWORD))
        {

            *reg = i;
            *w = 1;
            *addr_type = REGSTR;
            return 0;
        }
    }
    return -1;
}

/**** DEBUG TOOLS *****/
void log_buff(char b[][MAXWORD])
{

    printf("\n=> buffer:\n\t[");
    for (int i = 0; i < BUFFSIZE; i++)
    {
        printf("%i:%s ", i, b[i]);
    }
    printf("]\n=> end\n");
}