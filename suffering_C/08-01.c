/*
 * else文
 * if文の処理は与えられた条件が真のときに実行された。
 * else文は、if文に与えられた条件が偽のときに実行される処理を記述する際に使う。
 * 
 * ifとelseを組み合わせることで、様々な処理を場合分けして記述することができる。
 * なお、JevaScriptのように elseifのようなヒトツのトークンとして記述されることはない。
 * else if と区切って記述すること。
 * 
 */

#include <stdio.h>

int main(void)
{
    int i;

    printf("判定する値を入力してください: ");
    scanf("%d", &i);

    if(i < 1){
        printf("1より小さいです\n");
    }else if(i > 10){
        printf("10より大きいです\n");
    }else{
        printf("1から10の間の値です\n");
    }

    return 0;
}