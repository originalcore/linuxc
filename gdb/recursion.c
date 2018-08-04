#include <stdio.h>
#include <unistd.h>

static int g_cnt = 0;
static int g_time = 0;

/*
 * printout the backtrace in gdb
 * result in a very very long callstack
 */
void recursion(void)
{
	int i;

#ifdef UNLIMIT_LOOP
	/*
	 * no delay result
	 *
	 * 3536[52]
	 * 3537[52]
	 * 3538[52]
	 * Segmentation fault (core dumped)
	 */
	if (g_cnt > 10000)
	{
		g_cnt = 0;
		g_time++;
	}
#else
	if (g_cnt > 100000)
		return;
#endif

	g_cnt++;

	printf("%4d[%d]\n", g_cnt, g_time);

#ifdef DO_SOME_DELAY
	/*
	 * 1819[26]
	 * 1820[26]
	 * 1821[26]
	 * Segmentation fault (core dumped)
	 */
	/* do some delay */
	for (i = 0; i < 10000; i++);
#endif

	recursion();
}

int main(int argc, char *argv[])
{
	recursion();

	return 0;
}
