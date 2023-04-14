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

    printf("***数当てゲーム(レベル2)***\n");
    printf("3桁の数を当ててください!\n");
    printf("ただし各桁の数字は重複しません");

    int answer[3]; // answerという3つのintが入る変数を宣言
    int input[3];
    bool check;

    /* 答えを決める */
    for (int i = 0; i < 3; i++) {
        do {
            answer[i] = rand() % 10; // ランダムな0~9を設定
            // これまでの桁に同じ数字が使われているかをチェック
            for (int j = 0; j < i; j++) {
                check = false;
                if (answer[i] == answer[j]) { // 同じ数字はNG
                    break; // breakしたらdoを抜ける
                }
                check = true; // 重複なければOK
            }
        } while (i > 0 && check == false); // 1桁目はチェック不要
    }

    do { // ゲームが続く間はループする
        /* 結果を初期化 */
        int hit = 0;
        int blow = 0;

        /* 入力された予想を変数に格納 */
        for (int i = 0; i < 3; i++) {
            printf("%d桁目の予想を0~9の数字で入力してください:", i + 1);
            String inputStr;
            scanf("%s", inputStr);
            input[i] = atoi(inputStr); // atoiで文字列を数値に変換
        }

        /* 答え合わせ */
        for (int i = 0; i < 3; i++) {
            if (input[i] == answer[i]) {
                hit++; // 位置も数字も一致ならhit
            }
            for (int j = 0; j < 3; j++) {
                if (input[i] == answer[j] && i != j) {
                    blow++; // 位置は異なる数字はblow
                }
            }
        }

        /* 結果発表 */
        printf("%dヒット! %dブロー! ¥n", hit, blow);

        if (hit == 3) {
            // 正解
            printf("正解¥n");
            break;
        } else {
            // 不正解
            printf("続けますか？(0: 終了 0以外の数字: 続ける) :");
            String retryStr;
            scanf("%s", retryStr);

            // 終了するなら正解を表示
            if (atoi(retryStr) == 0) {
                printf("正解は");
                for (int i = 0; i < 3; i++) {
                    printf("%d", answer[i]);
                }
            }
        }

    } while (true); // ゲームが続く間はループする
}