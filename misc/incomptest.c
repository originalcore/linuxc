#include <stdio.h>

/*
 * 1. compile the program with flag below
 *	gcc -o incomptest incomptest.c -ftest-coverage -fprofile-arcs
 * 2. run the program
 *	./incomptest
 * 3. run gcov to find out
 *	code not executed which labeled with '#' symbal
 *
 * gcov incomptest.c
 */
int main(int argc, char *argv[])
{
	int a = 1;
	int b = 2;

	if (1 == a)
		printf("1 == a\n");
	else
		printf("1 != a\n");

	if (1 == b)
		printf("1 == b\n");
	else
		printf("1 != b\n");

	return 0;
}
