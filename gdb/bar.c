#include "bar.h"
#include <stdio.h>

void bar_func(void)
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
}

