/* #　は疑似命令文をあらわす。コンパイル前に処理される。
 * #include　は「説明書（ヘッダーファイル）」を読み込ませる疑似命令文。
 * #include <[ファイル名]>　の書式でヘッダーファイルを読み込む。
 * stdio.hはprintfなど、標準入出力にかかわる命令文を定義したヘッダーファイル。
 * これにより、printfなどの命令を実行できるようになる。
 * 
 */
#include <stdio.h>

int main(void)
{
    printf("HelloWorld");
    return 0;
}