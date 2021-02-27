#include <stdio.h>
#include <string.h>
#include <unistd.h> /* environ, execve */
#include <stdlib.h> /* exit */
#include <stdbool.h>

int main(int argc, char *argv[])
{
	extern char **environ;
	char **env;
	const char *val;
	int ret;
	char *child_argv[3];

	printf("\n --- check commandline args. --- \n");
	printf("argc: %d, argv[0]: %s\n", argc, argv[0]);
	printf("argv[1]: %s\n", argv[1]);
	printf("argv[2]: %s\n", argv[2]);
	printf("argv[3]: %s\n", argv[3]);
	printf("argv[4]: %s\n", argv[4]);

	printf("\n --- check environ items. --- \n");
	printf("environ[0](%p): %s\n", environ[0], environ[0]);
	printf("environ[1](%p): %s\n", environ[1], environ[1]);
	printf("environ[2](%p): %s\n", environ[2], environ[2]);
	printf("environ[3](%p): %s\n", environ[3], environ[3]);
	printf("environ[4](%p): %s\n", environ[4], environ[4]);

	printf("\n --- before setenv --- \n");
	printf("environ pointer: %p\n", environ);
	printf("show environ item if the key is SHELL, FOOOOO, or BARRRR.\n");
	env = environ;
	while(*env) {
		const char *val;

		val = *env;
		if (val && ( (strncmp(val, "SHELL", 5) == 0) || (strncmp(val, "FOOOOO", 6) == 0) || (strncmp(val, "BARRRR", 6) == 0) ) ) {
			printf("%s -> %s\n", *env, strchr(*env, '=') + 1);
		}
		env++;
		if (*env == NULL)
		{
			printf("\n*env is NULL. maybe, this is final line.\n");
		}
	}

	printf("\n --- setenvs --- \n");

	printf("setenv(\"FOOOOO\", \"fooooo\", 1);\n");
	ret = setenv("FOOOOO", "fooooo", 1);
	if (ret != 0)
	{
		perror("setenv error: ");
	}
	printf("environ pointer: %p\n\n", environ);

	printf("setenv(\"BARRRR\", \"bar===\", 1);\n");
	setenv("BARRRR", "bar===", 1);
	printf("environ pointer: %p\n\n", environ);

	printf("\n --- check env items exist. --- \n");

	printf("getenv(\"SHELL\"): %s\n", getenv("SHELL"));
	printf("getenv(\"FOOOOO\"): %s\n", getenv("FOOOOO"));
	printf("getenv(\"BARRRR\"): %s\n", getenv("BARRRR"));

	printf("\n --- check environ items again... items pointer is changed?? --- \n");
	printf("environ[0](%p): %s\n", environ[0], environ[0]);
	printf("environ[1](%p): %s\n", environ[1], environ[1]);
	printf("environ[2](%p): %s\n", environ[2], environ[2]);
	printf("environ[3](%p): %s\n", environ[3], environ[3]);
	printf("environ[4](%p): %s\n", environ[4], environ[4]);

	printf("\n --- after setenv, reset env pointer and reloop environ vars. --- \n");
	printf("show environ item if the key is SHELL, FOOOOO, or BARRRR.\n");
	env = environ;
	while(*env) {
		val = *env;
		if (val && ( (strncmp(val, "SHELL", 5) == 0) || (strncmp(val, "FOOOOO", 6) == 0) || (strncmp(val, "BARRRR", 6) == 0) ) )
			printf("%s -> %s\n", *env, strchr(*env, '=') + 1);
		env++;
		if (*env == NULL)
			printf("\n*env is NULL. end of environ list.\n");
	}

	child_argv[0] = "./called_func";
	child_argv[1] = "child_process";
	child_argv[2] = NULL;

	printf("\n ---- after here, goto child_func ----\n\n");

	execve(child_argv[0], child_argv, environ);

	return (EXIT_SUCCESS);
}