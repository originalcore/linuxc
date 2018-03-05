#include <stdio.h>
#include <stdlib.h>

struct person {
	int age;
	char name[20];
};

static struct person *p;
static void make_one_person(void)
{
	p = malloc(sizeof(struct person));
}

static void free_person(struct person *p)
{
	free(p);
}

static void show_age(struct person *p)
{
	printf("name %s, age %d\n", p->name, p->age);
}
