/*
 * if構文による比較
 * if([条件式]]) 結果が真の場合の処理
 * 
 * ☆C言語における真偽判定
 * 　真は「0以外の値」
 * 　偽は「0」
 * 　nullとかは、ないらしい
 * 　
 * ☆等価演算子 「==」
 * 　a == b -> true
 * 　JavaScriptやPHPのように、異なる型どうしの比較はできないっぽい？
 * 　厳密比較がないらしい
 * 　if( 1 == "1") printf("true\n"); // warning: comparison between pointer and integer
 */

#include <stdio.h>

int main(void)
{
    if( 1 == 1 ) printf("true\n");
    
}