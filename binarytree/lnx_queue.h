#ifndef __LNX_QUEUE__
#define __LNX_QUEUE__

struct lnx_queue_node {
	struct node *np; /* 数据域是二差树的节点 */
	struct lnx_queue_node *prev;
	struct lnx_queue_node *next;
};

void lnx_queue_enqueue(struct node *pn);
struct lnx_queue_node* lnx_queue_dequeue(void);
void free_lnx_queue_node(struct lnx_queue_node *p);
void lnx_queue_traverse(void (*visit) (struct lnx_queue_node*));
int lnx_queue_is_empty(void);

#endif
