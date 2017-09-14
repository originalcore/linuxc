#ifndef PARA_ALLOCATOR_H
#define PARA_ALLOCATOR_H

typedef struct {
	int number;
	char *msg;
} uint_t;

extern void alloc_uint(uint_t **);
extern void free_uint(uint_t *);

#endif
