# makeを実行すると、bit-shifting.cをコンパイルして実行します

.SILENT:
.PHONY: all

CC = gcc

all: bit-shifting

bit-shifting:
	$(CC) $@.c -o $@
	./$@
	rm -f $@
