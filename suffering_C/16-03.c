/*
 * 構造体の配列とポインタ
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[256];
    char deadline[256];
} Task;

int main(void)
{
    Task tasks_1[10];
    Task *tasks_2;

    tasks_2 = (Task *)malloc(sizeof(Task) * 10);
    
    int i, j;

    /*
     * 構造体の配列にデータを格納
     * 構造体配列[要素番号].[メンバ名] でアクセスできる。
     */
    for(i=0; i<10; i++){
        tasks_1[i].id = i;
        sprintf(tasks_1[i].name, "myTask_01-%02d", i);
        sprintf(tasks_1[i].deadline, "2020/12/31");
    }

    /*
     * 構造体のポインタ変数を使ってデータを格納する
     * [構造体ポインタ変数][要素番号].[メンバ名]。「.」は構造体の実変数のメンバへのアクセス。
     * 
     * (&[構造体ポインタ変数][要素番号])->[メンバ名]でもよい。　「->」は構造体のポインタ変数のメンバへのアクセス。
     * 
     */
    for(i=0; i<10; i++){
        tasks_2[i].id = i;
        sprintf(tasks_2[i].name, "yourTask-%02d", i);
        sprintf((&tasks_2[i])->deadline, "2030/01/01");
    }

    printf("tasks_1 shows...\n");
    for(i=0; i<10; i++){
        printf("%02d: %s( %s )\n",
            tasks_1[i].id,
            (&tasks_1[i])->name,
            tasks_1[i].deadline
        );
    }
    printf("\n");
    
    printf("tasks_2 shows...\n");
    for(i=0; i<10; i++){
        printf("%02d: %s( %s )\n",
            tasks_2[i].id,
            (&tasks_2[i])->name,
            tasks_2[i].deadline
        );
    }

    free(tasks_2);
    return 0;
}