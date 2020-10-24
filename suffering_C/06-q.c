#include <stdio.h>

int main(void)
{
    int price, dsct_1, dsct_3, dsct_5, dsct_8;

    printf("定価を入力してください: ");

    scanf("%d", &price); //変数priceに入力値を受け取り

    dsct_1 = price * 0.9;
    dsct_3 = price * 0.7;
    dsct_5 = price * 0.5;
    dsct_8 = price * 0.2;

    printf("1割引きの価格: %8d円\n", dsct_1);
    printf("3割引きの価格: %8d円\n", dsct_3);
    printf("5割引きの価格: %8d円\n", dsct_5);
    printf("8割引きの価格: %8d円\n", dsct_8);

    return 0;
}