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

    int answer[3]; // answerという3つのintが入る変数を宣言
    int input[3];
    bool check;

    /* 答えを決める */
    for (int i = 0; i < 3; i++) {
        do {
            answer[i] = rand() % 10; // ランダムな0~9を設定
            // これまでの桁に同じ数字が使われているかをチェック
            printf("%d¥n", answer[i]);
            for (int j = 0; j < i; j++) {
                check = false;
                if (answer[i] == answer[j]) { // 同じ数字はNG
                    printf("true");
                    break;
                }
                check = true; // 重複なければOK
            }
        } while (i > 0 && check == false); // 1桁目はチェック不要
    }
    return 0;
}
