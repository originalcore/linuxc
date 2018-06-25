#include <stdio.h>

void error_maker(void)
{
	char *str = NULL;

	*str = 'x';
}

int main(int argc, char *argv[])
{
	error_maker();
	return 0;
}
