#include <stdio.h>
#include <stdlib.h>
#include "lnx_queue.h"

void print_item(struct node *p)
{
	printf("-->%d", p->item);
}

int main(int argc, char **argv)
{
	struct node* p;
	int i;

	printf("Enqueue:\n");

	for (i = 1; i < argc; i++)
	{
		if (is_empty())
			printf("empty\n");

		printf("\nenqueue %d\n", atoi(argv[i]));
		p = make_node(atoi(argv[i]));
		enqueue(p);

		printf("head");
		traverse(print_item);
	}
	printf("\n===========================\n");
	if (is_empty())
		printf("empty\n");

	printf("Dequeue:\n");
	while ((p = dequeue()))
	{
		printf("dequeue %d\t", p->item);

		printf("head");
		traverse(print_item);
		printf("\n");
		free_node(p);
	}
	printf("\n");

	return 0;
}
