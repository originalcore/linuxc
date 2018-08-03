#include "interface.h"

static int g_value = 0;

void set_value(int value)
{
	g_value = value;
}

int get_value(void)
{
	return g_value;
}
