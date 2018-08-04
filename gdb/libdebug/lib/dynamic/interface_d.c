#include "interface.h"

static int g_value_d = 0;

void set_value_d(int value)
{
	g_value_d = value;
}

int get_value_d(void)
{
	return g_value_d;
}
