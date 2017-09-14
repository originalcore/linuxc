#ifndef _OUTPUT_VALUE_
#define _OUTPUT_VALUE_

typedef struct {
	int number;
	char msg[20];
} uint_t;

extern void set_uint(uint_t *);
#endif
