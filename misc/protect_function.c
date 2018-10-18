#include <stdio.h>

/*
 * If an expression results in false (0),
 * the assert function causes the application to fail
 * and an error to be generated to stdout.
 * To disable asserts within an application,
 * the NDEBUG can be defined before the assert.h last included
 */
//#define NDEBUG
#include <assert.h>

void foo(int value)
{
	assert(1 == value);

	return;
}

int main(int argc, char *argv[])
{
	foo(1);
	foo(2);

	return 0;
}
