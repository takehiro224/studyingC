#include <stdio.h>
#include <stdlib.h>

typedef char String[1024];

int iscanf(void)
{
    String inputStr;
    scanf("%s", inputStr); // キーボードから1行分の文字列入力を受け付ける命令
    return atoi(inputStr); // 文字列を整数に変換する
}

int calcPayment(int dividend, int divisor)
{
    // 総額を人数で割る(端数も保持) 1000円 / 3人 = 333.333
    double dnum = (double)dividend / divisor;
    // 100円未満を切り捨てる 333.333 / 100 = 3.33333 => 3 * 100 => 一人300円(100円未満切り捨てる)
    int person = (int)(dnum / 100) * 100;
    // 元の値と比較して、小さければ100円未満があったので100円上乗せ
    if (dnum > person) {
        person = person + 100; // 300円なので100円上乗せして1人400円
    }
    return person;
}

void showPayment(int general, int manager, int numbers)
{
    printf("*** 支払額 ***\n");
    printf("1人あたり%d円(%d人)、幹事は%d円です。\n", general, numbers - 1, manager);
}

int main(void)
{
    // 計算データ入力
    printf("支払い総額を入力してください: ");
    int amount = iscanf();
    printf("参加人数を入力してください: ");
    int people = iscanf();

    // 割り勘の計算
    int pay = calcPayment(amount, people);

    // 幹事の支払額を計算
    int payorg = amount - pay * (people - 1);

    // 結果の表示
    showPayment(pay, payorg, people);

    return 0;
}