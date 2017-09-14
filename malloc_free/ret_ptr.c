#include <stdio.h>
#include <string.h>
#include "ret_ptr.h"

static const char *days[] = {
	"Sun",
	"Mon",
	"Tue",
	"Wen",
	"Thu",
	"Fri",
	"Sat"
};

char *get_a_day(int idx)
{
	static char buf[20];
	strcpy(buf, days[idx]);

	printf("buf = %p[%s]\n", buf, buf);
	/* 返回指向已分配内存的指针 */
	return buf;
}
