#include <stdio.h>
#include "circularlinkedlist.h"

void print_item(struct node *p)
{
	printf("%d ", p->item);
}

int main(int argc, char **argv)
{
	struct node* p = make_node(10);
	insert(p);
	p = make_node(5);
	insert(p);
	p = make_node(90);
	insert(p);

	traverse(print_item);
	printf("\n");

	p = search(5);
	delete(p);
	free_node(p);
	traverse(print_item);
	destroy();
	printf("\n");

	p = make_node(100);
	enqueue(p);
	p = make_node(200);
	enqueue(p);
	p = make_node(250);
	enqueue(p);
	while ((p = dequeue())) {
		print_item(p);
		free_node(p);
	}
	printf("\n");
	return 0;
}
