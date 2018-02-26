#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int toggle = 0;

	while (1)
	{
		printf("toggle = %d\n", toggle);
		sleep(2);
		toggle ^= 1;
	}
}
