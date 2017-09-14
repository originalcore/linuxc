#ifndef _RET_ALLOCATOR_H_
#define _RET_ALLOCATOR_H_

typedef struct {
	int number;
	char *msg;
} uint_t;

extern uint_t *alloc_uint(void);
extern void free_uint(uint_t *);

#endif
