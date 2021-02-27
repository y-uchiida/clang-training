#include <stdio.h>
#include <string.h>
#include <unistd.h> /* environ, execve */
#include <stdlib.h> /* exit */
#include <stdbool.h>

int main(int argc, char *argv[])
{
	extern char **environ;
	char **env = environ;
	const char *val;

	printf("\n --- this is main() of called_func.c --- \n");

	printf("environ pointer in called_func: %p\n", environ);
	printf("show environ item if the key is SHELL, FOOOOO, or BARRRR.\n");

	while(*env) {
		val = *env;
		if (val && ( (strncmp(val, "SHELL", 5) == 0) || (strncmp(val, "FOOOOO", 6) == 0) || (strncmp(val, "BARRRR", 6) == 0) ) )
		// if (val)
			printf("%s -> %s\n", *env, strchr(*env, '=') + 1);
		env++;
		if (*env == NULL)
			printf("\n*env is NULL. end of environ list.\n");
	}

	printf("\n");

	printf("argc: %d, argv[0]: %s\n", argc, argv[0]);
	printf("argv[1]: %s\n", argv[1]);
	printf("argv[2]: %s\n", argv[2]);
	printf("argv[3]: %s\n", argv[3]);
	printf("argv[4]: %s\n", argv[4]);

	printf("getenv(\"SHELL\"): %s\n", getenv("SHELL"));
	printf("getenv(\"FOOOOO\"): %s\n", getenv("FOOOOO"));
	printf("getenv(\"BARRRR\"): %s\n", getenv("BARRRR"));

}