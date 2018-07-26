#include "foo.h"
#include <stdio.h>

void foo_func(void)
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
}

