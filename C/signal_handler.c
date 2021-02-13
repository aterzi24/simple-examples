#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig)
{
	printf("you sneaky, do you think you can exit?\nHaha..NO!\n");
}

int main()
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		exit(0);
	while (1) ;
	return 0;
}
