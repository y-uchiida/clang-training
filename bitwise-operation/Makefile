# makeを実行すると、biwise-oparation.cをコンパイルして実行します

.SILENT:
.PHONY: all

CC = gcc

all: bitwise-operation

bitwise-operation:
	$(CC) $@.c -o $@
	./$@
	rm -f $@
