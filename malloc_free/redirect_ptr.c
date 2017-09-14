#include "redirect_ptr.h"

static const char *days[] = {
	"Sun",
	"Mon",
	"Tue",
	"Wen",
	"Thu",
	"Fri",
	"Sat"
};

void get_a_day(const char **day)
{
	static int i = 0;

	/* 指向静态分配的内存 */
	*day = days[i % 7];
	i++;
}
