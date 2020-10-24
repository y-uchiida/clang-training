/*
 * for文での繰り返し
 * for([初期値]; [条件]; [値の更新]){
 *      [繰り返し内容];
 * }
 * 
 * [値の更新]の後ろには、セミコロンが不要なので注意が必要
 * 
 * ☆if文もswitchと同様、breakで途中離脱できる
 * 
 */

#include <stdio.h>

int main(void)
{
    int i;
    printf("数値を入力: ");
    scanf("%d", &i);
    for(i; i>0; i--){
        if(i > 100){
            printf("100より大きい値は処理しません\n");
            break;
        }
        printf("%d\n", i);
    }
    return 0;
}