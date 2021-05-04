#include <unistd.h> /* fork & execve, environ & pid_t */
#include <sys/wait.h> /* waitpid */
#include <sys/types.h> /* wait options */
#include <signal.h> /* signal functions */
#include <stdlib.h> /* exit */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int another_func()
{
	printf("this is another func.\n");
	return (EXIT_SUCCESS);
}

void main()
{
	pid_t	pid;
	int		status;
	char	*test_string;

	printf("before forking process.\n");
	strcpy(test_string, "this is test string.");

	pid = fork(); /* forkで、プロセスを分岐する */
	if (pid == 0)
	{	/* fork()で生成された子プロセスには、pid = 0 が返ってくる */
		/* 子プロセスの処理はpid == 0 の条件で記述できる */
		printf("\t - pid: %d, this is child process.\n", pid);

		/* 子プロセスは親プロセスのコピーなので、事前に用意しておいた変数の値や
		** 参照するメモリ領域は親プロセスと同一になる
		*/
		printf("\t - *test string pointer in child process: %p\n", test_string);
		exit(EXIT_SUCCESS);
	}
	else if(pid > 0)
	{ /* 親プロセスになった元のプロセスには、pidは子プロセスのプロセス番号が返ってくる */
		printf("\t - pid: %d, this is parent process.\n", pid);
		printf("\t - *test string pointer in parent process: %p\n", test_string);
	}
	else if (pid < 0)
	{
		printf("error: faild forking process.\n");
		exit(EXIT_FAILURE);
	}
	while (waitpid(pid, &status, 0) <= 0);
	printf("after finishing child process %d(status: %d).\n", pid, status);
	return ;
}