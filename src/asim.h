#ifndef _ASIM_H_
#define _ASIM_H_

#define MAXLEN 128
#define MAXWORD 64
#define ADDRSIZE 8

int process_line(char l[MAXLEN]);
void log_buff(char b[][MAXWORD]);

typedef enum __addr_type
{
    REGSTR,
    MEMRY
} addr_type;


    #endif // _ASIM_H_