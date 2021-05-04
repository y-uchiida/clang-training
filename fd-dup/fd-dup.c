#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int		fd_to_read;
	int		fd_to_write;
	int		restore_STDIO[2];
	char	*file_to_read = "bar.txt";
	char 	*file_to_write = "foo.txt";
	char	*write_content = "my test string\n";

	printf("--- filedescriptor manipuration test ---\n");

	restore_STDIO[0] = dup(STDIN_FILENO);
	printf("restore_STDIO[0](STDIN_FILENO): %d\n", restore_STDIO[0]);

	restore_STDIO[1] = dup(STDOUT_FILENO);
	printf("restore_STDIO[1](STDOUT_FILENO): %d\n", restore_STDIO[1]);

	/* dupで複製した標準出力へのディスクリプタに書き込みする -> ターミナルに表示される */
	write(restore_STDIO[1], "test output\n", 12); /* 標準出力に出る */

	fd_to_write = open(file_to_write, O_CREAT|O_RDWR|O_TRUNC|O_APPEND, S_IRWXU|S_IRWXG|S_IRWXO);

	write(fd_to_write, write_content, strlen(write_content) + 1);

	printf("test write to STDOUT before dup2\n"); /* 標準出力に出る */
	write(STDOUT_FILENO, "write fd 1\n", 12); /* 標準出力に出る */

	dup2(fd_to_write, STDOUT_FILENO);
	printf("test write to STDOUT after dup2\n"); /* ファイルに書き込まれる */
	write(STDOUT_FILENO, "write fd 1 again\n", 17); /* ファイルに書き込まれる */
	write(STDOUT_FILENO, "\n", 1); /* ファイルに書き込まれる */

	dup2(restore_STDIO[1], STDOUT_FILENO);

	printf("restore STDOUT descriptor\n"); /* 標準出力に出る */

	return (0);

}