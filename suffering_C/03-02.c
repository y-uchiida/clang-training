/* 改行は文字列中の改行は、\nで表現できる
 * \tはタブ文字で、単語の頭ぞろえができる
 */

#include <stdio.h>

int main(void)
{
    printf("Hello\n");
    printf("World\n");

    printf("\n");

    printf("name\tAlice\n");
    printf("age\t6\n");

    return 0;
}