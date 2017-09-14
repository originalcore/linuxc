#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ret_allocator.h"

uint_t *alloc_uint(void)
{
	uint_t *p = malloc(sizeof(uint_t));
	if (p == NULL)
	{
		perror("out of memory\n");
		exit(1);
	}

	p->number = 3;
	p->msg = malloc(20);
	strcpy(p->msg, "ret_alloc");

	return p;
}

void free_uint(uint_t *p)
{
	free(p->msg);
	free(p);
}
