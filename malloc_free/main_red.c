#include <stdio.h>
#include "redirect_ptr.h"

int main(int argc, char *argv[])
{
	const char *firday = NULL;
	const char *secday = NULL;

	/* 两层指针做参数,所指的内存空间应该解释成一个指针变量 */
	get_a_day(&firday);
	get_a_day(&secday);
	printf("first day %s, second day %s\n", firday, secday);
	return 0;
}
