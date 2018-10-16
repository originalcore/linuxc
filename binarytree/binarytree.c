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
 *
 * 第一个参数是数
 */
void pre_order(BiTree bTree, void(*visit)(TreeNode *))
{
	if (!bTree)
		return;

	visit(bTree);
	pre_order(bTree->left, visit);
	pre_order(bTree->right, visit);
}

/*
 * 中序遍历(左根右)
 * 先遍历所有左子节点
 * 再访问根
 * 再遍历所有右子节点
 */
void in_order(BiTree bTree, void(*visit)(TreeNode *))
{
	if (!bTree)
		return;

	in_order(bTree->left, visit);
	visit(bTree);
	in_order(bTree->right, visit);
}

/*
 * 后序遍历(左右根)
 * 先遍历所有左子节点
 * 再遍历所有右子节点
 * 再访问根
 */
void post_order(BiTree bTree, void(*visit)(TreeNode *))
{
	if (!bTree)
		return;

	post_order(bTree->left, visit);
	post_order(bTree->right, visit);
	visit(bTree);
}

int tree_leavess(BiTree bTree)
{
	if (!bTree)
		return 0;

	return 1 + tree_leavess(bTree->left) + tree_leavess(bTree->right);
}

int tree_depth(BiTree bTree)
{
	/*
	 * dl:depth of left child
	 * dr:depth of right child
	 */
	int dl, dr;

	if (!bTree)
		return 0;

	dl = tree_depth(bTree->left);
	dr = tree_depth(bTree->right);

	/* 深度去左右子树大的 */
	return 1 + (dl > dr ? dl : dr);
}

void tree_destroy(BiTree bTree)
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

void show_item_infos(TreeNode *pTNode, const char *msg)
{
	if (pTNode)
		printf("%d's %s:", pTNode->item, msg);
	else
		printf("%s:", msg);
}

/* 先序创建二叉树:根结点 -> 左子树 -> 右子树 */
/* 按提示输入421003006500700 */
BiTree precreate_btree(void (*prompt)(TreeNode *, const char *child), TreeNode *parent, const char *msg)
{
	DataType item;
	BiTree bTree = NULL;

	prompt(parent, msg);

	/*
	 * BugFix : *** stack smashing detected ***
	 * scanf %d 对应32位
	 * 如果item只有8位将导致栈溢出
	 */
	scanf("%d", &item);

	/* 用0来结束创建节点 */
	if (item == 0)
		bTree = NULL;
	else
	{
		bTree = make_node(item);
		bTree->left = precreate_btree(show_item_infos, bTree, "left");
		bTree->right = precreate_btree(show_item_infos, bTree, "right");
	}

	return bTree;
}

/* fork a tree */
BiTree fork_tree(BiTree bTree)
{
	TreeNode *lchild;
	TreeNode *rchild;
	TreeNode *pTNode;

	if (!bTree)
		return NULL;

	lchild = fork_tree(bTree->left);
	rchild = fork_tree(bTree->right);
	pTNode = make_node(bTree->item);
	pTNode->left = lchild;
	pTNode->right = rchild;

	return pTNode;
}

/*
 * 查找节点
 * 成功返回相应节点指针
 * 失败返回NULL
 */
TreeNode *find_node(BiTree bTree, DataType item)
{
	TreeNode *pTNode;

	if (!bTree)
		return NULL;
	else
	{
		if (item == bTree->item)
			return bTree;
		else
		{
			/* 沿着左子树查找 */
			if ((pTNode = find_node(bTree->left, item)))
				return pTNode;

			/* 沿着右子树查找 */
			if ((pTNode = find_node(bTree->right, item)))
				return pTNode;

			/* 未查找到该节点 */
			return NULL;
		}
	}
}

int level_of_leaf(BiTree bTree, TreeNode *pTNode)
{
	int level;

	/* 空树层号为0 */
	if (bTree == NULL)
		return 0;
	/* 根节点层号为1 */
	if (bTree->item == pTNode->item)
		return 1;
	else
	{
		/* 在左子树寻找 */
		level = level_of_leaf(bTree->left, pTNode);
		if (level >= 1)
			return level + 1;
		/* 在右子树寻找 */
		level = level_of_leaf(bTree->right, pTNode);
		if (level >= 1)
			return level + 1;

		/* 没有该节点 */
		return -1;
	}
}

BiTree insert_bst(BiTree bTree, DataType data)
{
	/* 开始进行插入操作 */
	TreeNode *pTNode = make_node(data);

	/* 如果此时是空树,将该节点作为根节点 */
	if (!bTree)
		bTree = pTNode;

	/*
	 * 已存在相同节点
	 * 则不进行插入操作
	 */
	if (find_node(bTree, data))
		return bTree;

	TreeNode *parent;
	TreeNode *child = bTree; /* 参考节点 */
	while (child)
	{
		parent = child;
		/*
		 * 插入数据和参考节点比较
		 * 插入数据比参考节点数据小,则将参考节点调整为左节点
		 * 插入数据比参考节点数据大,则将参考节点调整为右节点
		 */
		child = (data < child->item) ? child->left : child->right;
	}
	/*
	 * 上面循环结束后将找到插入点位置
	 *				parent
	 *			   /	  \
	 *child==>> left	  right <<==child
	 */
	if (data < parent->item)
		parent->left = pTNode;
	else
		parent->right = pTNode;

	return bTree;
}

/* 创建二叉排序树(binary search tree) */
BiTree create_bst(int array[], int len)
{
	int i;
	BiTree bTree = NULL;

	for (i = 0; i < len; i++)
		bTree = insert_bst(bTree, array[i]);

	return bTree;
}

/* BST从根节点一直往左走,直到无路可走就可得到最小值 */
TreeNode *bst_find_min(BiTree bTree)
{
	/* 空树 */
	if (!bTree)
		return NULL;

	/* 左子树是空 */
	if (!bTree->left)
		return bTree;

	/* 沿着左子树查找 */
	return bst_find_min(bTree->left);
}

/* BST从根节点一直往右走,直到无路可走就可以得到最大值 */
TreeNode *bst_find_max(BiTree bTree)
{
	/* 空树 */
	if (!bTree)
		return NULL;

	/* 右子树是空 */
	if (!bTree->right)
		return bTree;

	/* 沿着右子树查找 */
	return bst_find_max(bTree->right);
}

/* BST查找某节点 */
TreeNode *bst_find_node(BiTree bTree, DataType data)
{
	/* 空树或已经遍历了所有节点未找到 */
	if (!bTree)
		return NULL;

	if (data < bTree->item)
		return bst_find_node(bTree->left, data);
	else if (data > bTree->item)
		return bst_find_node(bTree->right, data);
	else
		return bTree;
}

/* BST查找某节点非递归版本 */
TreeNode *bst_find_node_nonrecursion(BiTree bTree, DataType data)
{
	TreeNode *pTNode = bTree;
	while (pTNode)
	{
		if (data == pTNode->item)
			return pTNode;

		/* 要找的数比节点小则遍历左子树,大则遍历右子树 */
		pTNode = (data < pTNode->item) ? pTNode->left : pTNode->right;
	}

	/* 空树或已经遍历了所有节点未找到 */
	return NULL;
}
