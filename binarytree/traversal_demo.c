#include <stdio.h>
#include "binarytree.h"

int main(int argc, char **argv)
{
	/* 根据前序和中序遍历结果构造二叉树 */
	unsigned char pre_seq[] = { 4, 2, 1, 3, 6, 5, 7 };
	unsigned char in_seq[] = { 1, 2, 3, 4, 5, 6, 7 };
	/*
	 *		    4
	 *		   / \
	 *       2	   6
	 *      / \   / \
	 *     1   3  5  7
	 */

	printf("Create a tree with pre and in sequence\n");
	BiTree bTree = init(pre_seq, in_seq, 7);

	printf("pre: ");
	pre_order(bTree, print_item);
	putchar('\n');

	printf("pre_non: ");
	pre_order_nonrecursion(bTree);
	putchar('\n');

	printf("in: ");
	in_order(bTree, print_item);
	putchar('\n');

	printf("in_non: ");
	in_order_nonrecursion(bTree);
	putchar('\n');

	printf("post: ");
	post_order(bTree, print_item);
	putchar('\n');

	printf("post_non: ");
	post_order_nonrecursion(bTree);
	putchar('\n');

	printf("level: ");
	level_order(bTree);
	putchar('\n');
	printf("Tree count = %d depth = %d\n", tree_leavess(bTree), tree_depth(bTree));

	printf("find node 1, 3, 7, 9\n");
	DataType find_this[] = {1, 3, 7, 9};
	TreeNode *pTNode;
	int i;
	for (i = 0; i < sizeof(find_this) / sizeof(find_this[0]); i++)
	{
		pTNode = find_node(bTree, find_this[i]);
		if (pTNode)
			printf("Node %d found\n", pTNode->item);
		else
			printf("Node %d ain't exist\n", find_this[i]);
	}

	tree_destroy(bTree);

	return 0;
}
