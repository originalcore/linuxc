#ifndef __LNX_QUEUE__
#define __LNX_QUEUE__

struct lnx_queue_node {
	struct node *np; /* 数据域是二差树的节点 */
	struct lnx_queue_node *prev;
	struct lnx_queue_node *next;
};

void enqueue(struct node *pn);
struct lnx_queue_node* dequeue(void);
void free_lnx_queue_node(struct lnx_queue_node *p);
void traverse(void (*visit) (struct lnx_queue_node*));
int is_empty(void);

#endif
