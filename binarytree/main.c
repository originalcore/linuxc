#include <stdio.h>
#include "binarytree.h"

void print_item(TreeNode *pTNode)
{
	printf("%d", pTNode->item);
}

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

	printf("Create btree by pre order\n");
	BiTree preTree = NULL;
	preTree = precreate_btree(show_item_infos, NULL, "root");
	printf("pre: ");
	pre_order(preTree, print_item);
	putchar('\n');

	printf("count=%d depth=%d\n", tree_leavess(bTree), tree_depth(bTree));

	tree_destroy(bTree);

	return 0;
}
