#include <stdio.h>

void funcA(int x) // int型を受け取る関数
{
    x = 100;
}

void funcB(int x[3]) // int型配列を受け取る関数
{
    x[0] = 100;
}

int main(void)
{
    int a = 5; // int型変数を宣言(初期値は5)
    int b[3];  // 配列を宣言
    b[0] = 5;  // int型配列の先頭要素を5で初期化

    funcA(a);
    funcB(b);

    printf("a=%d, b[0]=%d\n", a, b[0]);
    // 実行結果: a=5, b[0]=100
    return 0;
}