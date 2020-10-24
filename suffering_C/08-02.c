/*
 * switch文での条件分岐
 * 
 * switch([判定する値]){
 *      case [比較する値]:
 *          等しいときに処理する内容
 *          break;
 *      default:
 *          いずれの条件にも当てはまらないときに処理する内容
 *          break;
 * }
 * 
 * ☆C言語のswitch文は、整数値しか比較できない！！
 *  
 */

#include <stdio.h>

int main(void)
{
    int i;

    printf("判定する値を入力: ");
    scanf("%d", &i);

    switch(i){
        case 1:
            printf("%d位は金メダル！\n", i);
            break;
        case 2:
            printf("%d位は銀メダル！\n", i);
            break;
        case 3:
            printf("%d位は銅メダル！\n", i);
            break;
        default:
            printf("メダルがもらえるのは3位までです...\n");
            break;
    }

    return 0;
}