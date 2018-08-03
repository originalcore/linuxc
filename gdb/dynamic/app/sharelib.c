#include <stdio.h>
#include "interface.h"

int main(int argc, char *argv[])
{
	int value = 911;

	printf("value = %d\n", get_value());
	set_value(value);
	printf("set value = %d\n", value);
	printf("value = %d\n", get_value());

	return 0;
}
