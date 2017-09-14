#include <stdio.h>
#include "ret_ptr.h"

int main(int argc, char *argv[])
{
#if 0
	char *fir = NULL;
	char *sec = NULL;

	fir = get_a_day(0);
	sec = get_a_day(1);

	printf("%s, %s\n", fir, sec);
	printf("%p[%s], %p[%s]\n", fir, fir, sec, sec);
#else
	/*
	 * printf中参数入栈顺序是从右到左
	 * 所以先调用get_a_day(1), 再调用get_a_day(0)
	 * get_a_day返回一个指针指向一块静态数据区buffer
	 * fir->buffer
	 * sec->buffer
	 * 所以结果是第二次调用get_a_day函数的结果
	 */
	printf("%s, %s\n", get_a_day(0), get_a_day(1));
#endif
	return 0;
}
