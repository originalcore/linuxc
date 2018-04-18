#include <stdio.h>

/*
 * 1. 	gcc -g -o add2line_usage add2line_usage.c
 * 2.	dmesg
 * traps: add2line_usage[127212] trap divide error ip:400534 sp:7ffeda89cc90 error:0 in add2line_usage[400000+1000]
 * 3.	addr2line -e add2line_usage 400534
 * figure out the line number of the error
 */
int func(int a, int b)
{
	return a / b;
}

int main(int argc, char *argv[])
{
	int x = 10;
	int y = 0;

	printf("%d / %d = %d\n", x, y, func(x, y));

	return 0;
}
