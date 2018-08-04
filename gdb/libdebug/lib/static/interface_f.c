#include "interface.h"

static int g_value_s = 0;

void set_value_s(int value)
{
	g_value_s = value;
}

int get_value_s(void)
{
	return g_value_s;
}
