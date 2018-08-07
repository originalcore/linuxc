#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < 3; i++)
		printf("%s, %d\n", __FUNCTION__, __LINE__);

	return 0;
}
