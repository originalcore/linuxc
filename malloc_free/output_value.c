#include <string.h>
#include "output_value.h"

void set_uint(uint_t *p)
{
	/* ignore NULL parameter */
	if (p == NULL)
		return;

	p->number = 3;
	strcpy(p->msg, "output_value");
}
