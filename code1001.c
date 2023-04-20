#include <stdio.h>

void funcA(int x) // int型を受け取る関数
{
    x = 100;
}

void funcB(int x[3]) // int型配列を受け取る関数
{
    x[0] = 100;
}