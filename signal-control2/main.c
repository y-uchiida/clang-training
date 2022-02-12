#include "signal-control2.h"

int main (void)
{
	printf("proccess start. pid: %d\n", getpid());

	set_signalhandler();

	while (1) {
		pause();
		if (g_receive_signal == SIGUSR1) {
			printf("SIGUSR1 received!\n");
		}
		g_receive_signal = 0;
	}

	return (EXIT_SUCCESS);
}
