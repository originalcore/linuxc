#include <stdio.h>

void do_something(void)
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
}

int main(int argc, char *argv[])
{
	int i, j;

	/*
	 * (gdb) display i
	 * (gdb) display j
	 */
	for (i = 0, j = 100; i < 20 && j > 50; i++, j--)
		do_something();

	return 0;
}
