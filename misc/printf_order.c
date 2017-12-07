#include <stdio.h>

int foo(void)
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
	return 0;
}

int bar(void)
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
	return 0;
}

int main(int argc, char *argv[])
{
	printf("%d, %d\n", foo(), bar());
	return 0;
}
