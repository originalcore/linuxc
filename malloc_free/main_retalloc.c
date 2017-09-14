#include <stdio.h>
#include "ret_allocator.h"

int main(int argc, char *argv[])
{
	uint_t *p = NULL;

	p = alloc_uint();
	printf("No : %d, msg : %s\n", p->number, p->msg);
	free_uint(p);
	p = NULL;
	return 0;
}
