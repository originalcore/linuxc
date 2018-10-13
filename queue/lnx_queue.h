#ifndef __LNX_QUEUE__
#define __LNX_QUEUE__

struct node {
	unsigned char item;
	struct node *prev;
	struct node *next;
};

struct node* make_node(unsigned char item);
void enqueue(struct node *p);
struct node* dequeue(void);
void free_node(struct node *p);
void traverse(void (*visit) (struct node*));

#endif
