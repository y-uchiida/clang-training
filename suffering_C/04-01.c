/*
 * 出力変換指定子
 * printfへの引数となる文字列内で利用できる、%から始まる記号。
 * %d は、後から与えられる整数値に置き換えて出力される。
 * %s は文字。文字列型の変数とかを置き換えるのに利用するっぽい
 * printf("%d\n", 1234); -> 1234
 */

#include <stdio.h>

int main(void)
{
    printf("%d is bigger than %d\n", 10, 2);
    return 0;
}