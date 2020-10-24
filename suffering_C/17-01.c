/* 
 * ファイル操作とファイルポインタ
 * FILE型ののポインタ変数をファイルポインタと呼ぶ。
 * FILE *fp;
 * fopen([ファイル名],モード) でファイルを扱うためのポインタ(ファイルポインタ)を設定する。
 * fclose(ファイルポインタ) でファイルを閉じる。
 * fp = fopen('./test.txt', a+);
 * fclose(fp);
 * 
 * fscanf([ファイルポインタ], [出力変換指定子], )
 */

#include <stdio.h>

int main(void)
{

    char str[1000 + 1] = "";
    FILE *fp, *read;
    fp = fopen("./aset/myTestData.txt", "a+"); /* testMyData.txt用のファイルポインタを設定 */

    printf("入力された文字列を、一行ずつ ./aset/myTestData.txtに書き込みします。\n");
    printf("受け取れる文字は半角英数字と記号のみです。\n");
    printf("文字を入力してください...\n");

    while (1)
    {
        if (scanf("%1000[^\n]%*[^\n]", str) == 0)
        {
            /* 改行文字だけが入力された場合、取得できた文字数は0
             * -> 読み取りを終了する
             */
            break;
        }
        scanf("%*c"); /* 1000文字を超えて入力された場合、次の文字読み取りの際に影響するので、あふれている分を読み飛ばす */

        if (*str != '\n')
        {
            fprintf(fp, "%s\n", str); /* 標準入力から取得した文字列をファイルに追記する */
            sprintf(str, "\n");       /* ループで大量に書き込みされてしまうので、文字列を空にする */
        }
    }

    fclose(fp); /* ファイルポインタを閉じる */

    /* 読込用のファイルポインタを設定 */
    read = fopen("./aset/myTestData.txt", "r");

    printf("./aset/myTestData.textの内容は以下となりました：\n");
    while (fscanf(read, "%1000s", str) != EOF) /* 1行ずつ読み込みし、EOFに到達したら終了 */
    {
        printf("%s\n", str);
    }

    return 0;
}
