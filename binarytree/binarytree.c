#include <stdlib.h>
#include <stdio.h>
#include "binarytree.h"
#include "lnx_queue.h"

static struct node* make_node(unsigned char item)
{
	struct node *p = NULL;

	p = malloc(sizeof(struct node));
	p->item = item;
	p->left = NULL;
	p->right = NULL;

	return p;
}

static void free_node(struct node *p)
{
	free(p);
}

struct node* init(unsigned char VLR[], unsigned char LVR[], int n)
{
	struct node *t;
	int k;

	if (n <= 0)
		return NULL;

	for (k = 0; VLR[0] != LVR[k]; k++);

	t = make_node(VLR[0]);
	t->left = init(VLR + 1, LVR, k);
	t->right = init(VLR + 1 + k, LVR + 1 + k, n - k - 1);

	return t;
}

/*
 * 前序遍历(根左右)
 * 先访问根
 * 再遍历所有左子节点
 * 再遍历所有右子节点
 */
void pre_order(struct node *t, void(*visit)(struct node *))
{
	if (!t)
		return;

	visit(t);
	pre_order(t->left, visit);
	pre_order(t->right, visit);
}

/*
 * 中序遍历(左根右)
 * 先遍历所有左子节点
 * 再访问根
 * 再遍历所有右子节点
 */
void in_order(struct node *t, void(*visit)(struct node *))
{
	if (!t)
		return;

	in_order(t->left, visit);
	visit(t);
	in_order(t->right, visit);
}

/*
 * 后序遍历(左右根)
 * 先遍历所有左子节点
 * 再遍历所有右子节点
 * 再访问根
 */
void post_order(struct node *t, void(*visit)(struct node *))
{
	if (!t)
		return;

	post_order(t->left, visit);
	post_order(t->right, visit);
	visit(t);
}

int count(struct node *t)
{
	if (!t)
		return 0;

	return 1 + count(t->left) + count(t->right);

}

int depth(struct node *t)
{
	/*
	 * dl:depth of left child
	 * dr:depth of right child
	 */
	int dl, dr;

	if (!t)
		return 0;

	dl = depth(t->left);
	dr = depth(t->right);

	/* 深度去左右子树大的 */
	return 1 + (dl > dr ? dl : dr);
}

void destroy(struct node *t)
{
	post_order(t, free_node);
}

/* 传入参数是二叉树根 */
void level_order(struct node *root)
{
	if (root == NULL)
		return;

	/* 出列的节点 */
	struct Qnode *popup_node;

	/*
	 * 1. 将二叉树的根结点入队列
	 * 2. 将队头元素出队列
	 * 3. 并将队头元素的左子树的根结点(非空)
	 * 	  右子树的根结点(非空)分别入队列
	 * 4. 重复2,3,直至队列中没有元素
	 */
	enqueue(root);
	while (!is_empty())
	{
		popup_node = dequeue();
		printf("%d\t", popup_node->np->item);
		if (popup_node->np->left)
			enqueue(popup_node->np->left);
		if (popup_node->np->right)
			enqueue(popup_node->np->right);
	}

	/* free queue */
	traverse(free_Qnode);
}
