/*
 * 1. #define疑似命令による定数の宣言
 * #define [定数名(慣習的に、大文字で宣言)] 値
 * 
 * 2. constによる関数内定数の宣言
 * 特定のスコープの中でのみ扱いたい定数は、
 * const int num  = 100;
 * のように宣言することができる。
 * constをつけて宣言された変数は、値の再代入ができなくなる。
 * num = 200; // -> エラーになる
 * 
 * 3. enumによる定数の複数宣言
 * enum{
 *   [定数名],
 *   [定数名],
 *   ...
 *   ...
 *   ...
 * }
 * 
 * のように、複数の定数をenumでまとめて宣言できる。
 * enumで宣言された定数は、上から順番に0, 1, という整数値が与えられる。
 * 
 */

#include <stdio.h>
#define AUTHOR "uchiida"
#define CREATE_DATE "2020_01_10"
#define EXCISETAX 0.1

int main(void)
{
    int price;
    printf("本体価格を入力: ");
    scanf("%d", &price);
    printf("税込価格: %d円\n", (int)(price * (1 + EXCISETAX)));

    printf("\n");

    enum
    {
        ZERO,
        FIRST,
        SECOND,
        THIRD
    };

    printf("enumで宣言した定数\n");
    printf("ZERO: %d,\nFIRST: %d,\nSECOND; %d,\nTHIRD: %d\n", ZERO, FIRST, SECOND, THIRD);
    return 0;
}