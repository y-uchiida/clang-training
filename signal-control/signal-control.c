#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

static void signal_handler(int signum);
static void signal_handler_for_child(int signum);
static void signal_handler_for_grandchild(int signum);
static void set_signalhandler();
static void set_signalhandler_for_child();
static void set_signalhandler_for_grandchild();
static void parent_say(char *str);
static void child_say(char *str);
static void grandchild_say(char *str);
static void putnbr(int n);

int		main()
{
	int parent_pid = getpid();

	parent_say("this is parent proc (pid: ");
	putnbr(parent_pid);
	parent_say(")\n");

	set_signalhandler();

	if (fork() == 0)
	{
		int child_pid = getpid();

		child_say("this is child proc (pid: ");
		putnbr(child_pid);
		child_say(")\n");

		set_signalhandler_for_child();

		if (fork() == 0)
		{
			int grandchild_pid = getpid();

			grandchild_say("this is grandchild proc (pid: ");
			putnbr(grandchild_pid);
			grandchild_say(")\n");

			set_signalhandler_for_grandchild();

			grandchild_say("start infinit loop in grand child. this loop end if SIGINT(Ctrl + C) sent.\n");
			while(1);
		}
		child_say("start infinit loop in child. this loop end if SIGINT(Ctrl + C) sent.\n");
		while(1);
	}

	parent_say("start infinit loop. process this loop end if SIGQUIT(Ctrl + \\) sent.\n");
	while (1);
	return (EXIT_SUCCESS);
}

static void signal_handler(int signum)
{
	if (signum == SIGINT)
		parent_say("SIGINT to parent is ignored.\n");
	else if (signum == SIGUSR1)
		parent_say("SIGUSR1 to parent is ignored.\n");
	else if (signum == SIGUSR2)
		parent_say("SIGUSR2 controled in parent signal handler.\n");
	else if (signum == SIGTSTP)
		parent_say("SIGTSTP to parent is ignored.\n");
	else if (signum == SIGCHLD)
		parent_say("SIGCHLD to parent sent.\n");
	else if (signum == SIGQUIT)
	{
		parent_say("SIGQUIT to parent sent. exit\n");
		exit(EXIT_SUCCESS);
	}
}

static void signal_handler_for_child(int signum)
{
	if (signum == SIGINT)
	{
		child_say("SIGINT to child sent. exit\n");
		exit(EXIT_SUCCESS);
	}
	else if (signum == SIGUSR1)
		child_say("SIGUSR1 to child is ignored.\n");
	else if (signum == SIGQUIT)
		child_say("SIGQUIT to child is ignored.\n");
}

static void signal_handler_for_grandchild(int signum)
{
	if (signum == SIGUSR1)
		grandchild_say("SIGUSR1 to grandchild is ignored.\n");
	else if (signum == SIGQUIT)
		grandchild_say("SIGQUIT to grandchild is ignored.\n");
}

static void	set_signalhandler()
{
	signal(SIGINT, signal_handler);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGCHLD, signal_handler);
	parent_say("set signal handling for parent process.\n");
}

static void	set_signalhandler_for_child()
{
	signal(SIGINT, signal_handler_for_child);
	signal(SIGUSR1, signal_handler_for_child);
	signal(SIGQUIT, signal_handler_for_child);
	child_say("set signal handling for child process.\n");
}

static void	set_signalhandler_for_grandchild()
{
	signal(SIGUSR1, signal_handler_for_grandchild);
	signal(SIGQUIT, signal_handler_for_grandchild);
	grandchild_say("set signal handling for grandchild process.\n");
}

static void parent_say(char *str)
{
	printf("\033[35m");
	printf("%s", str);
	write(STDIN_FILENO, "\x1b[m", 4);
}

static void child_say(char *str)
{
	printf("\033[34m");
	printf("%s", str);
	write(STDIN_FILENO, "\x1b[m", 4);
}

static void grandchild_say(char *str)
{
	printf("\033[33m");
	printf("%s", str);
	write(STDIN_FILENO, "\x1b[m", 4);
}

static void putnbr(int n)
{
	if (n >= 10)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
	  putchar('0' + n);
}