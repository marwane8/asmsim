#include <stdio.h>
#include <string.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = 5;
    *y = 12;
}

typedef enum _type
{
    REG,
    MEM
} type;

int main()
{

    int n1 = 0x1F, n2 = 0;
    // swap(&n1, &n2);

    printf("res num: %i \n", n1);
}