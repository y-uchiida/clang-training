# clang-training

## whats this
C言語の基本的な機能を試したり、サンプル的なコードを書いたり、学習した内容をまったり記録していきます。

## suffering_C(2019.12~2020.01)
以前に「苦しんで覚えるC言語」の内容に取り組んだときに作成したコードです。  
言語仕様の基礎から、構造体の扱い方あたりまでを学習しました。

## bit-shifting(2020.10.25)
C言語でのビットシフト演算について、実際にコードを書いて動作を確認しました。  
左シフト演算は常に論理シフトであることなど、実用的な知識になりました。

## bitwise-operation(2020.10.25)
C言語のビット演算について、コードを書いて動作を確認しました。  
いろいろ触っているうちに理解が進み、2進数の表現がようやく腑に落ちました。  
この実習で気づいた内容をブログにまとめました:  
[符号付き2進数は最上位ビットだけ1のときが最小値になる](https://memoryclip.rambling-bit.com/2020/10/computer-science/smallest-in-signed-binary-number/)  

## environment-variables(2021.02.27)
C言語での環境変数の取扱いについて、細かい動作を調査しました。  
setenvした場合のenvrionポインタの挙動や、子プロセスへの環境変数の引き渡しなど、なかなか情報が見つからず、それなら実際に動かしてみることに。  
ドキュメントにも書いていないし、普通に使うだけなら意識しない部分も、動かしてみたらしっくりくる仕様になっていました。  
得られた知見を簡単に[commentary.md](https://github.com/y-uchiida/clang-training/blob/main/environment-variables_in_c/commentary.md)にまとめています。