#include <stdio.h>
#include "para_allocator.h"

int main(int argc, char *argv[])
{
	uint_t *p = NULL;

	alloc_uint(&p);
	printf("No : %d, msg : %s\n", p->number, p->msg);
	free_uint(p);
	p = NULL;
	return 0;
}
