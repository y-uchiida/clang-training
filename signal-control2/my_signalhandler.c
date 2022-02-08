#include "signal-control2.h"

void my_signalhandler(int signal_type)
{
	printf("my signalhandler called.\n");
	g_receive_signal = signal_type;

	return ;
}
