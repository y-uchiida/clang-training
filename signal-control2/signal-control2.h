#ifndef _SIGNAL_CONTROL2_H_
# define _SIGNAL_CONTROL2_H_

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <bits/sigaction.h>

int g_receive_signal;

void my_signalhandler(int signal_type);
void set_signalhandler(void);


#endif
