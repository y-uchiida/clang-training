#!/bin/bash

rm -f foo.txt
gcc fd-dup.c

echo ----- exec a.out start -----
./a.out
echo ----- exec a.out  end  -----
echo

echo ----- result below -----
cat ./foo.txt
echo ----- result  end  -----
rm -f foo.txt