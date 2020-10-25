/* ビットシフト
** 演算の種類は①論理演算と2算術演算の2つがある
** 論理演算は、単純にビットをずらすだけ。数値の符号を考慮しない。
** unsignedの型に対して行われる方式。
** 算術演算は、最上位ビットを数値の符号と考えてビットをずらす。
** 負の数を含む型に対して行われる方式。
** C言語でのシフト演算は、「<< n」と「>> n」を使う。
** 「<< n」は、nビットの左シフトを行う。
** 「>> n」は、nビットの右シフトを行う。
*/

#include <stdio.h>

int main ()
{

	//挙動をわかりやすくするため、1バイトの型であるcharを利用
	unsigned char	bit_unsigned;
	unsigned char	tmp_unsigned;
	signed char		bit_signed_plus;
	signed char		bit_signed_minus;
	signed char		tmp_signed;

	//unsigned char は符号がないので、
	//論理シフトでビットシフトが行われる
	bit_unsigned = 127; // 255は、バイナリ表記(2進数)で 01111111

	printf("1.論理演算でのビットシフトの例：\n");
	printf("\t符号なし整数127(01111111)を1ビット左にシフトすると、254(11111110)になります\n");
	printf("\tbit_unsigned(%d) << 1\n", bit_unsigned);
	tmp_unsigned = bit_unsigned << 1;
	printf("\t実行結果 -> %d\n", tmp_unsigned);
	printf("\n");

	printf("\t符号なしの数値は論理シフト演算が行われ、空いた部分を0で補います\n");
	printf("\t符号なし整数127(01111111)を2ビット左にシフトすると、桁あふれして252(11111100)になります\n");
	printf("\tbit_unsigned(%d) << 2\n", bit_unsigned);
	tmp_unsigned = bit_unsigned << 2;
	printf("\t実行結果 -> %d\n", tmp_unsigned);
	printf("\n");

	printf("\t右シフトの場合も、論理シフト演算では開いた部分を0を補います\n");
	printf("\t127(01111111)を2ビット右に論理シフトすると、31(00011111)になります\n");
	printf("\tbit_unsigned(%d) >> 2\n", bit_unsigned);
	tmp_unsigned = bit_unsigned >> 2;
	printf("\t実行結果 -> %d\n", tmp_unsigned);

	printf("\n");

	//符号付きの値の場合の右シフトは、算術シフト演算が行われる
	bit_signed_plus = 0b01000000;
	bit_signed_minus = 0b11111100;

	printf("2.算術演算でのビットシフトの例：\n");
	printf("\t符号付きの数値を処理するための算術シフト演算では、次の特徴があります\n");
	printf("\t1: 最上位ビットの一つ手前が桁あふれする\n");
	printf("\t2: 右シフトした際の空き部分は、最上位ビットと同じ値で補う\n");

	printf("\n");

	printf("\t符号付き整数-4(0b11111100)を1ビット右にシフト演算すると、-2(0b11111110)になります\n");
	printf("\tbit_signed_minus(%d) >> 1\n", bit_signed_minus);
	tmp_signed = bit_signed_minus >> 1;
	printf("\t実行結果 -> %d\n", tmp_signed);
	printf("\n");

	printf("\t符号つき整数64(0b01000000)を1ビット右にシフト演算すると、32(0b00100000)になります\n");
	printf("\tbit_signed_plus(%d) >> 1\n", bit_signed_plus);
	tmp_signed = bit_signed_plus >> 1;
	printf("\t実行結果 -> %d\n", tmp_signed);
	printf("\n");

	printf("3.符号付きの数値の左ビットシフト:\n");
	printf("\tC言語では符号つき整数を左ビットシフトして符号ビットの値が変わるときの動作は未定義です\n");
	printf("\t主要なコンパイラ(gccやclang)では、論理シフト演算を行い、符号が変化します\n");

	printf("\n");

	printf("\t符号つき整数64(0b01000000)を1ビット左にシフト演算すると、-128(0b10000000)になります\n");
	printf("\tbit_signed_plus(%d) << 1\n", bit_signed_plus);
	tmp_signed = bit_signed_plus << 1;
	printf("\t実行結果 -> %d\n", tmp_signed);

	return (0);
}
