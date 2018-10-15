#ifndef __LNX_QUEUE__
#define __LNX_QUEUE__

#include "node.h"
struct lnx_queue_node {
	TreeNode *tree_node; /* 数据域是二差树的节点 */
	struct lnx_queue_node *prev;
	struct lnx_queue_node *next;
};

typedef struct lnx_queue_node QueueNode;

void lnx_queue_enqueue(TreeNode *pTNode);
QueueNode* lnx_queue_dequeue(void);
void free_lnx_queue_node(QueueNode *pQNode);
void lnx_queue_traverse(void (*visit) (QueueNode*));
int lnx_queue_is_empty(void);

#endif
