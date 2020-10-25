/* ビット論理演算子
** 1.論理積(AND): &
**   同じ桁のビットの値が等しければ1を返す
**   そうでなければ0を返す
**
** 2.論理和(OR): |
**   同じ桁のビットの値のいずれかが1であれば1を返す
**   両方とも0のときは0を返す
**
** 3.排他的論理和(XOR): ^
**   同じ桁のビットのいずれかが1でもう一方が0ときに1を返す
**   両方0、または両方1の場合は0を返す
**
** 4.補数(NOT): ~
**   2つのビット列の比較ではなく、1つのビット列に対してその値を反転する
**   1であれば0を、0であれば1を返す
*/

#include <stdio.h>

void print_binary(char b);

int main()
{
	unsigned char	b1;
	unsigned char	b2;
	unsigned char	tmp;


	printf("ビット演算子の挙動確認\n");

	printf("1. 論理積(AND): &\n");
	printf("\t2つのビット列の同じ桁ごとに比較し、両方が1なら1を返します\n");
	b1 = 0b01010101;
	b2 = 0b11110000;
	tmp = b1 & b2; // -> 0b01010000

	printf("\tb1: "); print_binary((char)b1); printf("\n");
	printf("\tb2: "); print_binary((char)b2); printf("\n");
	printf("\t& : "); print_binary((char)tmp); printf("\n");

	printf("\n");

	printf("\t特定の位置のビットだけを0にすることができます\n");
	printf("\t上位2つのビットを0にし、それ以外は変更しない例:\n");
	b1 = 0b10111101;
	b2 = 0b00111111;
	tmp = b1 & b2; // -> 0b00111101

	printf("\tb1: "); print_binary((char)b1); printf("\n");
	printf("\tb2: "); print_binary((char)b2); printf("\n");
	printf("\t& : "); print_binary((char)tmp); printf("\n");

	printf("\n");

	printf("2.論理和(ＯＲ): |\n");
	printf("\t2つのビット列の同じ桁ごとに比較し、どちらかが1なら1を返します\n");
	b1 = 0b01010101;
	b2 = 0b11110000;
	tmp = b1 | b2; // -> 0b11110101

	printf("\tb1: "); print_binary((char)b1); printf("\n");
	printf("\tb2: "); print_binary((char)b2); printf("\n");
	printf("\t| : "); print_binary((char)tmp); printf("\n");

	printf("\n");

	printf("\t任意の位置のビットを1にすることができます\n");
	printf("\t上位2つのビット列を1にし、それ以外は変更しない例:\n");
	b1 = 0b01000111;
	b2 = 0b11000000;
	tmp = b1 | b2; // -> 0b11000111;

	printf("\tb1: "); print_binary((char)b1); printf("\n");
	printf("\tb2: "); print_binary((char)b2); printf("\n");
	printf("\t| : "); print_binary((char)tmp); printf("\n");

	printf("\n");

	printf("3.補数(NOT): ^\n");
	printf("\t2つのビット列の同じ桁ごとに比較し、いずれかが1でもう一方が0のときに1を返します\n");

	b1 = 0b01010101;
	b2 = 0b11110000;
	tmp = b1 ^ b2; // -> 0b10100101;

	printf("\tb1: "); print_binary((char)b1); printf("\n");
	printf("\tb2: "); print_binary((char)b2); printf("\n");
	printf("\t^ : "); print_binary((char)tmp); printf("\n");

	printf("\n");

	printf("\t同じビット列をXOR演算すると0になるので、ビット列の初期化などに利用できます\n");
	b1 = 0b11110000;
	b2 = 0b11110000;
	tmp = b1 ^ b2; // -> 0b00000000;

	printf("\tb1: "); print_binary((char)b1); printf("\n");
	printf("\tb2: "); print_binary((char)b2); printf("\n");
	printf("\t^ : "); print_binary((char)tmp); printf("\n");

	printf("\n");

	printf("4.排他的論理和(XOR): ~\n");
	printf("\t1つのビット列の桁それぞれの値を反転します\n");

	b1 = 0b00001111;
	tmp = ~ b1; // -> 0b11110000;

	printf("\t  b1: "); print_binary((char)b1); printf("\n");
	printf("\t~ b1: "); print_binary((char)tmp); printf("\n");

	printf("\n");

	printf("\t使いどころとしては、そのままですがビット列をまとめて反転させたいときに利用できます\n");
	printf("\tまた、名前の通り1の補数を得られるので、減算の処理に応用できます。\n");

	return (0);
}


/*
** print_binary(char b):
** 文字列型に対して、その値を2進数にして表示する
*/
void print_binary(char b)
{
	unsigned char	mask;

	printf("0b");
	//maskの値を1ビットずつ右シフトしていき、0になるまで実行
	for (mask = 0b10000000; mask; mask >>= 1)
	{
		//maskの値とand演算し、maskビット側で1が入っている桁の値が
		//1なら、演算結果は0より大きくなる = その桁のビットは1
		putchar((b & mask) ? '1' : '0');
	}
}
