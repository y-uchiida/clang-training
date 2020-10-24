/*
 * オリンピック開催年を判別する
 */

#include <stdio.h>

int main(void)
{
    int year;
    
    printf("オリンピック開催年を判別します\n");
    printf("判別する年を、4桁の西暦年で入力してください: ");
    scanf("%d", &year);

    if(year % 4 == 0){
        printf("%d年は、夏季オリンピックの開催予定年です。\n", year);
    }
    if(year % 4 == 2){
        printf("%d年は、冬季オリンピックの開催予定年です。\n", year);
    }
    if(year % 4 == 1 || year % 4 == 3){
        printf("%d年は、オリンピックの開催年ではありません。\n", year);
    }
    

    return 0;
}