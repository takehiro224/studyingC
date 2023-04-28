#include <stdio.h>

void printIntByAddress(int* valAddr)
{
    printf("格納されている値は: %d\n", *valAddr);
}