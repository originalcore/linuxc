#ifndef __LNX_QUEUE__
#define __LNX_QUEUE__

struct Qnode {
	struct node *np; /* 数据域是二差树的节点 */
	struct Qnode *prev;
	struct Qnode *next;
};

void enqueue(struct node *pn);
struct Qnode* dequeue(void);
void free_Qnode(struct Qnode *p);
void traverse(void (*visit) (struct Qnode*));
int is_empty(void);

#endif
