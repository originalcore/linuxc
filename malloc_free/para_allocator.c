#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "para_allocator.h"

void alloc_uint(uint_t **pp)
{
	uint_t *p = malloc(sizeof(uint_t));
	if (p == NULL)
	{
		perror("out of memroy\n");
		exit(1);
	}

	p->number = 3;
	p->msg = malloc(20);
	strcpy(p->msg, "para_allocator");

	/* 指向动态分配的内存 */
	*pp = p;
}

void free_uint(uint_t *p)
{
	free(p->msg);
	free(p);
}
