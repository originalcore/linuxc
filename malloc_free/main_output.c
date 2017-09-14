#include <stdio.h>
#include "output_value.h"

int main(int argc, char *argv[])
{
	uint_t u;

	set_uint(&u);
	printf("No : %d, msg : %s\n", u.number, u.msg);
	return 0;
}
