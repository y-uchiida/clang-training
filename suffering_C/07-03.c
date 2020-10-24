/*
 * if構文とブロック
 * if文での真偽判定の後に{}で囲むと、条件に一致した際に実行される一連の処理を記述できる。
 * if(true){
 *      printf("必ず表示されます");
 * }
 * 
 */

#include <stdio.h>

int main(void)
{
    int score;
    printf("点数を入力してください: ");
    scanf("%d", &score);

    if(score > 100){
        printf("100より大きいので修正します\n");
        score = 100;
    }
    printf("入力された点数: %d点\n", score);
}