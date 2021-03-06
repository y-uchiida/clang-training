/* 
 * mallocによる動的配列の作成
 * 
 * ポインタ変数にmalloc()で作成したアドレスを渡すことで、柔軟に配列を作成できる。
 * malloc()で作成されたメモリ領域は、自動的に解放されることがない。
 * free()を呼び出してプログラム上で明示的に解放してやる必要がある。
 * malloc()で確保したメモリを解放し忘れることをメモリリークといい、動作速度低下の原因になる。
 * 適切なタイミングで忘れずにfree()を呼出しするようにしなければならない。
 * 
 * 長期にわたって確保されるサイズの大きなメモリ領域をヒープと呼ぶことがあり、
 * これはmalloc()で作成されたメモリ領域を指すことも多い。
 * 
 * malloc([確保するメモリのサイズ]);
 * int *heap;
 * heap = (int *)malloc(sizeof(int) * 100);
 * if(heap == NULL){ exit; }
 * -> mallocで、int型100個分のメモリを確保する。
 * -> メモリ領域の確保ができた場合はvoid型のポインタを返す。void型ポインタはどの型のポインタにも代入できる。
 * -> ..のが仕様であるが、C++ コンパイラでは、void型のポインタを他の変数型のポインタに代入するとエラーが出るので
 * -> int * でint型のポインタ変数にキャストする必要がある。
 * -> メモリ領域の確保に失敗した場合は、NULLが返される。
 * -> メモリの確保ができなかった場合は、必要に応じてエラー処理を行う。
 * 
 * なお、mallocを利用するにはstdlib.hをインクルードする必要がある。
 * 
 * realloc()で、メモリ領域の変更ができる。
 * ポインタ変数 = realloc(既存のポインタ変数, 変更後のメモリサイズ)
 * 
 * heap = realloc(heap, (int *)sizeof(int) * 1000);
 * -> heapのメモリ領域を100から1000個分に拡張する。
 * -> 代入先のポインタ変数は、既存のポインタ変数と別のものにすることもできる
 *
 * realloc()はあとからメモリ領域を変更するという性質上、確保されるアドレスが連番にならない。
 * このような状態をフラグメンテーションといい、動作を不安定にする要因になる。
 * realloc()の呼び出し回数はなるべく少なくなるように、あらかじめ大きめの領域を確保したり
 * realloc()するときも大きめの領域を取り直すようにした方が良い。
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    int *heap;

    heap = (int *)malloc(sizeof(int) * 500);
    if(heap == NULL) exit(0);

    for(i=0; i<500; i++){
        heap[i] = i+1;
    }
    printf("%d\n", heap[10]);
    // -> 11

    heap = (int *)realloc(heap, sizeof(int) * 1000);
    heap[999] = 1000;
    
    printf("heap[999]: %d\n", heap[999]);
    //-> heap[999]: 1000

    free(heap);
    return 0;
}