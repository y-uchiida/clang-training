/*
 * バイナリファイルの取り扱い
 * バイナリファイル...0と1のみで内容が表現されたファイル。
 * 動作が高速だが人間が読んだり内容を編集するのは困難。
 * C言語においては、基本的な操作方法はcsvやtxtなどのテキストファイルとおなじ。
 * fopenやfcloseでファイルポインタを介して操作する。
 * 異なるのは、fopenの際のモード指定の末尾に、バイナリファイルであることを示すbを付与すること。
 * 
 * bfp = fopen("path/to/binary.dat", "a+b"); バイナリファイルの追記モードで、ファイルポインタbftを設定
 * ファイルへの書き込みは、fwrite()を利用できる。
 * fwrite([書き込みする変数のポインタ], [書き込みするサイズ], [書き込みする項目数], [バイナリファイルポインタ])
 * 
 * 読込はfreadが使える。
 * fread([読込先の変数のポインタ], [読込するサイズ], [読込する項目数], [バイナリファイルポインタ]);
 */

#include <stdio.h>

int main(void){

    FILE *bfp;
    char str[100] = "hello world";

    bfp = fopen("./aset/myBinary.dat", "wb");
    fwrite(str, sizeof(str), 1, bfp);
    fclose(bfp);

    bfp = fopen("./aset/myBinary.dat", "rb");
    fread(str, sizeof(str), 1, bfp);
    printf("%s\n", str);

    return 0;
}