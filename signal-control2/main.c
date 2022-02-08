#include "signal-control2.h"

int main (void)
{
	printf("proccess start. pid: %d\n", getpid());

	set_signalhandler();

	while (1) {
		if (g_receive_signal == SIGUSR1) {
			printf("SIGUSR1 received!\n");
		}
		pause();
	}

	return (EXIT_SUCCESS);
}
