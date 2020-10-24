#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * ポインタ変数のモードの覚書
 * p:    ポインタ変数モード、アドレス値にアクセス
 * *p:   実変数モード、保存されている値にアクセス
 * p[n]: nの実変数
 * (&p[n]): nのアドレス(ポインタとしての値)
 * 
 * 構造体において、
 * ・実変数のときは[構造体変数名].[メンバ名]　でアクセスできる
 * ・ポインタ変数のときは[構造体変数名]->[メンバ名]　でアクセスできる
 */

typedef struct
{
    char name[256];
    int age;
    int sex;
} People;

void InputPeople(People *data);
void ShowPeople(People data);

int main(void)
{
    int i, count, datasize;
    People *data;

    datasize = 10; // 10人分の領域を確保
    data = (People *)malloc(sizeof(People) * datasize);

    count = 0;
    while (1)
    {
        InputPeople(&data[count]); /* count番目の構造体要素のポインタをInputPeopleに渡す */
        if (data[count].age == -1)
        {
            break;
        }
        count++;

        if (count >= datasize)
        { // Peopleのメモリ領域を拡張
            datasize += 10;
            data = (People *)realloc(data, sizeof(People) * datasize);
        }
    }

    // (&data[0])->age = 100;
    // printf("%d\n", data[0].age);

    for(i=0; i<count; i++){
        ShowPeople(data[i]);
    }

    free(data);

    return 0;
}

void InputPeople(People *data)
{
    printf("名前を入力してください: ");
    scanf("%s", data->name); //->でdataの中のname要素の先頭のアドレスを取得している(ポインタ変数モード)

    printf("年齢を入力してください: ");
    scanf("%d", &data->age);

    printf("性別を入力してください(1-male, 2-female): ");
    scanf("%d", &data->sex);

    printf("\n");
}

void ShowPeople(People data)
{
    printf("名前: %s\n", data.name); //.でdataの中のname要素の値を取得している(実変数モード)
    printf("年齢: %d\n", data.age);

    if (data.sex == 1)
    {
        printf("性別: male\n");
    }
    else
    {
        printf("性別: female\n");
    }
    printf("\n");
}