#include <stdio.h>

extern "C" void foo(void);

void foo(void)
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
}
