#include <stdio.h>
#include "foo.c"

int main(int argc, char *argv[])
{
	make_one_person();
	p->age  = 1;
	strcpy(p->name, "test");

	show_age(p);

	free_person(p);
	return 0;
}
