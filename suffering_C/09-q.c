/*
 * 九九を表示する 
 */

#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 1; i <= 9; i++)
    {
        printf("\n★ %dの段！ ★\n", i);
        for (j = 1; j <= 9; j++){
            printf("%2d × %2d = %2d\n", i, j, i * j );
        }
    }

    return 0;
}