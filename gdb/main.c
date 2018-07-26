#include <stdio.h>
#include <stdlib.h>
#include "foo.h"
#include "bar.h"

void stub_func(void)
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
}

void args_func(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
}

int main(int argc, char *argv[])
{
	int a;
	int b;

	args_func(argc, argv);

	if (argc >= 3)
	{
		/* init value a and b */
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	}

	stub_func();

	foo_func();

	/* take a break here if a > b */
	/*
	 * (gdb) b N if a > b
	 * N is the line number of current file(main.c)
	 *
	 * (gdb) b 49
	 * (gdb) set args 1 2
	 * (gdb) r
	 *
	 * (gdb) set args 2 3
	 * (gdb) r
	 */
	bar_func();
	return 0;
}
