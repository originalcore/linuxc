#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "example.h"

int main(int argc, char *argv[])
{
	struct people *p, *p1;
	struct people *pos;

	p = malloc(sizeof(struct people));
	strcpy(p->name, "ZeroWay");

	p1 = malloc(sizeof(struct people));
	strcpy(p1->name, "zeroway");

	/* ZeroWay is a good man and programer */
	list_add(&p->list1, &programer);
	list_add(&p->list2, &good_man);

	/* zeroway is only a good man */
	list_add(&p1->list2, &good_man);

	printf("Find out the programers :");
	list_for_each_entry(pos, &programer, list1)
		printf("name = %s\n", pos->name);

	printf("Who is a good man?\n");
	list_for_each_entry(pos, &good_man, list2)
		printf("name = %s, who is a good man\n", pos->name);
}
