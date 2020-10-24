/*
 * #define疑似命令で固定的な処理を定義することも可能
 * #define PLS printf("%d\n", 1+1)
 * -> 関数内でPLS; と入力すると、 2が出力される。
 * 
 * さらに、defineで定義する定数名の後ろに引数をつけることで、簡易的に関数を作成することもできる
 * このような使い方をマクロと呼ぶ。
 * #define PUTS(STR) printf("%s\n", STR)
 * -> PUTS(a); で、文字列を出力できる
 */

#include <stdio.h>
#define NPLUSM sum = n + m;
#define PUTS(STR) printf("%s\n", STR)

int main(void){
    int n, m, sum;
    char word[13] = "hello world!";

    n = 10;
    m = 40;
    NPLUSM

    printf("sum: n + m = %d\n", sum);
    PUTS(word);
}