#include <stdio.h>
#include "interface.h"

int main(int argc, char *argv[])
{
	int value = 911;

	printf("dynamic test start\n");
	printf("value = %d\n", get_value_d());
	set_value_d(value);
	printf("set value = %d\n", value);
	printf("value = %d\n", get_value_d());
	printf("dynamic test end\n");

	printf("static test start\n");
	printf("value = %d\n", get_value_s());
	set_value_s(value);
	printf("set value = %d\n", value);
	printf("value = %d\n", get_value_s());
	printf("static test end\n");

	return 0;
}
