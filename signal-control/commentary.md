# commentary of signal-control
fork()したプロセスにおいて、シグナルハンドラがどのように動作するのかを見てみました。

## 調査環境
念のため、ウチイダの環境を記載しておきます。
- Host OS: Windows 10 Pro 20H2 build 19042.964
- WSL: ver2
- Guset OS: Ubuntu 20.04.2 LTS (Focal Fossa)
- compiler: gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

## 得られた知見
1. プロセスをforkすると、分岐もとのプロセスのシグナルハンドラの設定を引き継ぐ
2. キーボード入力でのシグナル送信(Ctrl + C, Ctrl + Z, Ctrl + \\)は、プロセスグループに対して行われる
3. forkしたプロセスが所属するプロセスグループは、明示的に変更しない限りおおもとのプロセスと同じものになる。親子関係が直列に並ぶわけではない

## 実験ソースコード
signal-control.cひとつにすべてまとめてあります。  
`gcc signal-control.c` だけでコンパイル可能です。

## ソースコードの内容を簡潔に
以下の場合の挙動を確かめてみました。
- 親プロセスで、SIGINT, SIGUSR1, SIGUSR2, SIGTSTP, SIGCHLD, SIGQUIT のシグナルハンドラを設定する
- SIGQUIT のハンドラでは、シグナル検知のメッセージを表示したのちにexitする
- SIGQUIT 以外のシグナルでは、そのシグナルを検知した旨のメッセージを表示する
- 親プロセスをforkし、子プロセスでSIGINT, SIGUSR1, SIGQUITのハンドラを上書きする
- SIGINTシグナルを検知した場合にメッセージを返してexitするように設定する
- SIGQUITシグナルは、シグナル検知のメッセージ表示のみで、exitしない
- SIGUSR1シグナルは、親プロセスと同じくシグナル検知メッセージのみ表示するが、メッセージ内容は親プロセスのものから変更する
- 子プロセスをforkし孫プロセスをつくり、SIGUSR1, SIGQUITのハンドラを上書きする
- どちらのシグナルも子プロセスと同様に、シグナル見地のメッセージのみを表示するが、メッセージ内容は子プロセスのものから変更する

わかりづらいので、表にまとめてみます。
||親プロセス|子プロセス|孫プロセス|
|-------|----------|----------|---------|
|SIGINT |親プロセス用メッセージを表示|子プロセス用メッセージを表示<br>その後exit|設定しない|
|SIGUSR1|親プロセス用メッセージを表示|子プロセス用メッセージを表示|孫プロセス用メッセージを表示|
|SIGUSR2|親プロセス用メッセージを表示|設定しない|設定しない|
|SIGTSTP|親プロセス用メッセージを表示|設定しない|設定しない|
|SIGCHLD|親プロセス用メッセージを表示|設定しない|設定しない|
|SIGQUIT|親プロセス用メッセージを表字<br>その後exit|子プロセス用メッセージを表示|孫プロセス用メッセージを表示|
親、子、孫のどのプロセスからのメッセージかわかるように、メッセージの文字色を変更しています。

## 実験内容
### 実験1. キーボードからシグナルを送信してみる
ソースコードをコンパイルして実行します。  
```
$ gcc signal-control.c; ./a.out
this is parent proc (pid: 16738)
set signal handling for parent process.
start infinit loop. process this loop end if SIGQUIT(Ctrl + \) sent.
this is child proc (pid: 16739)
set signal handling for child process.
start infinit loop in child. this loop end if SIGINT(Ctrl + C) sent.
this is grandchild proc (pid: 16740)
set signal handling for grandchild process.
start infinit loop in grand child. this loop end if SIGINT(Ctrl + C) sent.
```  
親、子、孫プロセスが起動して、メッセージが表示されました。  
この状態で、まずはSIGTSTP(Ctrl + Z)を送信してみます。  
```
^ZSIGTSTP to parent is ignored.
SIGTSTP to parent is ignored.
SIGTSTP to parent is ignored.
```
3回、親プロセスのメッセージが表示されました。  
3つのプロセスとも、SIGTSTPに同じシグナルハンドラが設定されていることが確認できました。  

今度はSIGINT(Ctrl + C)を送信してみます。
```
^CSIGINT to child sent. exit
SIGINT to child sent. exit
SIGCHLD to parent sent.
SIGINT to parent is ignored.
```
子プロセスで設定したシグナルハンドラが2回動作しているように見えます。  
孫プロセスでシグナルハンドラを設定していないため、子プロセスの内容が引き継がれているようです。  
そのままの状態で、もう一度SIGINT(Ctrl + C)を送信してみます。
```
^CSIGINT to parent is ignored.
```
今度は、親プロセスのシグナルハンドラだけが動作しています。  
先ほどのシグナル送信で、子プロセスと孫プロセスが終了したため、これらのプロセスのシグナルハンドラは動作しなくなりました。
ここまでの内容から、派生元のプロセスで設定されたシグナルハンドラは、forkした先のプロセスでも引き継がれるということがわかりました。

### 実験2. kill コマンドでシグナルを送信してみる
今度はキーボードから送信できるシグナル以外のものを送信して、挙動を試してみます。
`kill`コマンドで、指定のプロセスに指定のシグナルを送信します。  
まずはkillコマンドを送信できるように、実験用プロセスをバックグランドで実行します。
```
$ ./a.out &
[1] 17324
$ this is parent proc (pid: 17324)
set signal handling for parent process.
start infinit loop. process this loop end if SIGQUIT(Ctrl + \) sent.
this is child proc (pid: 17325)
set signal handling for child process.
start infinit loop in child. this loop end if SIGINT(Ctrl + C) sent.
this is grandchild proc (pid: 17326)
set signal handling for grandchild process.
start infinit loop in grand child. this loop end if SIGINT(Ctrl + C) sent.
$
```
メッセージが表示された後、ターミナルのプロンプトが戻ってきます。  
この状態で、別のコマンドが入力できるようになります。  
ただし、実験用プロセスのメッセージにプロンプトの文字列が挟まってしまて、ちょっとみづらくなりました。  
可能なら、画面分割などをして、片方で実験用プロセスを起動し、もう一方でkill コマンドを実行してもよいかもしれません。

まずは親プロセスにSIGUSR1 シグナルを送ってみます。  
フォーマットは、`kill -[送信するシグナル名] [プロセスID]` です。  
```
$ kill -SIGUSR1 17324
SIGUSR1 to parent is ignored.
```
親プロセスから、メッセージが返ってきました。  
プロセスIDは起動時のメッセージに含まれていますが。ps コマンドでも確認できます。
プログラム名を初期設定のa.outのままにしていたら、以下のような表示になるはずです。
```
$ ps
  PID TTY          TIME CMD
 5543 pts/2    00:00:00 bash
17324 pts/2    00:06:15 a.out
17325 pts/2    00:06:15 a.out
17326 pts/2    00:06:15 a.out
17347 pts/2    00:00:00 ps
```
3つa.outが並んでいて、上から順番に親プロセス、子プロセス、孫プロセス　となります。  
つぎは、子プロセスと孫プロセスにもSIGUSR1 シグナルを送ってみます。
```
$ kill -SIGUSR1 17325
SIGUSR1 to child is ignored.
$
$ kill -SIGUSR1 17326
SIGUSR1 to grandchild is ignored.
$
```
それぞれ、対応するメッセージが返ってきます。  
では、キーボードから送信されたシグナルのように、複数のプロセスにまとめて送信される例を試してみます。  
kill コマンドは、プロセスグループに対してもシグナルを送信できます。  
`kill -[送信するシグナル名] -[プロセスグループID]`  

```
$ kill -SIGUSR1 -17324
SIGUSR1 to child is ignored.
SIGUSR1 to grandchild is ignored.
SIGUSR1 to parent is ignored.
```

親プロセスから派生した3つのプロセスから、メッセージが返ってきました。  
では、子プロセス(ここではPID 17325)をプロセスグループとしてkillコマンドを送信したら、  
子プロセスと孫プロセスだけにシグナルが送信できるでしょうか？
```
$ kill -SIGUSR1 -17325
-bash: kill: (-17325) - No such process
```
できませんでした。子プロセスはプロセスグループではないようです。

プロセスが所属するプロセスグループは、ps コマンドの-o オプションから確認できます。
```
$ ps -o pid,ppid,pgid,tty,time,cmd
  PID  PPID  PGID TT           TIME CMD
 5543  5542  5543 pts/2    00:00:00 -bash
17324  5543 17324 pts/2    00:19:07 ./a.out
17325 17324 17324 pts/2    00:19:07 ./a.out
17326 17325 17324 pts/2    00:19:07 ./a.out
17394  5543 17394 pts/2    00:00:00 ps -o pid,ppid,pgid,tty,time,cmd
```
子プロセス、孫プロセスのPGIDを見てみると、親プロセスのものになっています。  
子プロセスのプロセスIDは、PGIDの欄に出てきていません。  
多段forkしても、明示的に設定を変えない限り、おおもとのプロセスグループの所属が引き継がれるということがわかりました。
最後の確認として、kill コマンドから 実験用プログラムのプロセスグループにSIGINT シグナルを送信してみて、  
キーボードからシグナル送信(Ctrl + C)したのと同じ結果になるのかを見てみます。
```
$ kill -SIGINT -17324
SIGINT to child sent. exit
SIGINT to parent is ignored.
SIGCHLD to parent sent.
SIGINT to child sent. exit
$
$ ps 
  PID TTY          TIME CMD
 5543 pts/2    00:00:00 bash
17324 pts/2    00:23:54 a.out
17325 pts/2    00:23:27 a.out <defunct>
17410 pts/2    00:00:00 ps
```
親プロセスはひきつづき残っており、孫プロセスは消えました。  
子プロセス(17325)はすでに終了していますが、親プロセスが動作中なので`<defunct>`状態でプロセステーブル上に残っています。  
これがいわゆるゾンビプロセスです。
親プロセスが終了すると、子プロセスのゾンビも消えます。
```
$ kill 17324
$ ps
  PID TTY          TIME CMD
 5543 pts/2    00:00:00 bash
17431 pts/2    00:00:00 ps
[1]+  Terminated              ./a.out
```

## まとめ
forkしたプロセスとシグナルハンドラの関係を見てきました。  
とりあえずわかりやすさ優先でsignal()コマンドを使ってハンドリングしており、マルチスレッドの内容までは踏み込めていません。  
今後の課題として学んでいきたいと思います。