#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signal)
{
	printf("Singal handler processing...\n");
	psignal(signal, "Signal:");
}

int main(int argc, char *argv[])
{

	/* register the handler for SIGINT */
	signal(SIGINT, handler);

	while (1)
	{
		printf("Runing...\n");
		sleep(2);
	}

	return 0;
}
