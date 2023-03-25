#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // srand
#include <time.h>

// String型を作成(C言語にはString型が存在しない)
typedef char String[1024];

int main(void)
{
    // 乱数生成(乱数のタネを変更する*これを行わないと乱数が同じ数値になる)
    srand((unsigned)time(NULL));
}