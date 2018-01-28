#include <stdio.h>

int main(int argc, char **argv)
{
	register int i, nflg;

	nflg = 0;

	/*
	 * common ways of skipping initial arguments
	 * skip "-n" here
	 */
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n')
	{
		nflg++;
		argc--;
		argv++;
	}

	/* echo arguments */
	for (i = 1; i < argc; i++)
	{
		fputs(argv[i], stdout);
		if (i < argc - 1)
			putchar(' ');
	}

	if (nflg == 0)
		putchar('\n');

	return 0;
}
