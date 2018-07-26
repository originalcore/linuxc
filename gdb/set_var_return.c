#include <stdio.h>

int foo(int val)
{
	printf("val = %d\n", val);
	return 0;
}

int main(int argc, char *argv[])
{
	int a;
	int ret;

	a = 911;

	ret = foo(a);
	printf("ret = %d\n", ret);

	return 0;
}
