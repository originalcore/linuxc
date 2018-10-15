#include <stdlib.h>
#include <stdio.h>
#include "binarytree.h"
#include "lnx_queue.h"
#include "lnx_stack.h"

static TreeNode* make_node(unsigned char item)
{
	TreeNode *pTNode = NULL;

	pTNode = malloc(sizeof(TreeNode));
	pTNode->item = item;
	pTNode->left = NULL;
	pTNode->right = NULL;

	return pTNode;
}

static void free_node(TreeNode *pTNode)
{
	free(pTNode);
}

/* 返回一棵树 */
BiTree init(unsigned char VLR[], unsigned char LVR[], int n)
{
	int k;
	TreeNode *pTNode;

	if (n <= 0)
		return NULL;

	for (k = 0; VLR[0] != LVR[k]; k++);

	pTNode = make_node(VLR[0]);
	pTNode->left = init(VLR + 1, LVR, k);
	pTNode->right = init(VLR + 1 + k, LVR + 1 + k, n - k - 1);

	return pTNode;
}

/*
 * 前序遍历(根左右)
 * 先访问根
 * 再遍历所有左子节点
 * 再遍历所有右子节点
 */
void pre_order(TreeNode *pTNode, void(*visit)(TreeNode *))
{
	if (!pTNode)
		return;

	visit(pTNode);
	pre_order(pTNode->left, visit);
	pre_order(pTNode->right, visit);
}

/*
 * 中序遍历(左根右)
 * 先遍历所有左子节点
 * 再访问根
 * 再遍历所有右子节点
 */
void in_order(TreeNode *pTNode, void(*visit)(TreeNode *))
{
	if (!pTNode)
		return;

	in_order(pTNode->left, visit);
	visit(pTNode);
	in_order(pTNode->right, visit);
}

/*
 * 后序遍历(左右根)
 * 先遍历所有左子节点
 * 再遍历所有右子节点
 * 再访问根
 */
void post_order(TreeNode *pTNode, void(*visit)(TreeNode *))
{
	if (!pTNode)
		return;

	post_order(pTNode->left, visit);
	post_order(pTNode->right, visit);
	visit(pTNode);
}

int count(TreeNode *pTNode)
{
	if (!pTNode)
		return 0;

	return 1 + count(pTNode->left) + count(pTNode->right);
}

int depth(TreeNode *pTNode)
{
	/*
	 * dl:depth of left child
	 * dr:depth of right child
	 */
	int dl, dr;

	if (!pTNode)
		return 0;

	dl = depth(pTNode->left);
	dr = depth(pTNode->right);

	/* 深度去左右子树大的 */
	return 1 + (dl > dr ? dl : dr);
}

void destroy(BiTree bTree)
{
	post_order(bTree, free_node);
}

/* 传入参数是二叉树根 */
void level_order(BiTree bTree)
{
	if (bTree == NULL)
		return;

	/* 出列的节点 */
	struct lnx_queue_node *popup_node;

	/*
	 * 1. 将二叉树的根结点入队列
	 * 2. 将队头元素出队列
	 * 3. 并将队头元素的左子树的根结点(非空)
	 * 	  右子树的根结点(非空)分别入队列
	 * 4. 重复2,3,直至队列中没有元素
	 */
	lnx_queue_enqueue(bTree);
	while (!lnx_queue_is_empty())
	{
		popup_node = lnx_queue_dequeue();
		printf("%d\t", popup_node->tree_node->item);
		if (popup_node->tree_node->left)
			lnx_queue_enqueue(popup_node->tree_node->left);
		if (popup_node->tree_node->right)
			lnx_queue_enqueue(popup_node->tree_node->right);
	}

	/* free queue */
	lnx_queue_traverse(free_lnx_queue_node);
}

/*
 * 非递归遍历
 * 从节点出发向左走到头(边走边记录访问过的节点, 放到栈里)
 * 然后退回到该节点,再进入右子树,再重复前面操作
 *
 * 前序遍历
 * 1. 先访问节点数据
 * 2. 以后再访问该节点右孩子的数据(将其压入栈)
 * 3. 因而可以不记录该节点(左节点)而直接记录该节点的右孩子
 */
void pre_order_nonrecursion(BiTree bTree)
{
	TreeNode *pTNode = bTree;

	while (1)
	{
		while (pTNode)
		{
			/* 访问节点数据 */
			printf("%d", pTNode->item);

			/* 将右节点压入栈 */
			if (pTNode->right)
				lnx_stack_push(pTNode->right);

			/* 继续遍历左节点 */
			pTNode = pTNode->left;
		}

		/* 栈里所有数据访问结束 */
		if (lnx_stack_is_empty())
			break;

		/* 开始访问右节点 */
		pTNode = lnx_stack_pop();
	}
}

void in_order_nonrecursion(BiTree bTree)
{
	TreeNode *pTNode = bTree;

	while (1)
	{
		/* 线路记录 : 将沿路访问过的节点压入栈 */
		for (; pTNode != NULL; pTNode = pTNode->left)
			lnx_stack_push(pTNode);

		/* 所有节点都处理完 */
		if (lnx_stack_is_empty())
			break;

		/* 开始访问节点数据 */
		pTNode = lnx_stack_pop();
		printf("%d", pTNode->item);

		/* 访问右节点 */
		pTNode = pTNode->right;
	}
}

void post_order_nonrecursion(BiTree bTree)
{
	TreeNode *pTNode = bTree;

	while (pTNode != NULL || !lnx_stack_is_empty())
	{
		/* 线路记录 : 将沿路访问过的节点压入栈 */
		for (; pTNode != NULL; pTNode = pTNode->left)
			lnx_stack_push(pTNode);

		pTNode = lnx_stack_pop();
		printf("%d", pTNode->item);

		if (!lnx_stack_is_empty() && pTNode == lnx_stack_peek()->left)
			pTNode = lnx_stack_peek()->right;
		else
			pTNode = NULL;
	}
}
