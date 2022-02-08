#include "signal-control2.h"

void set_signalhandler(void)
{
	struct sigaction sa;

	sa.sa_handler = &my_signalhandler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa, NULL);
}
