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

	printf("TEST1 : create a tree with pre and in sequence\n");
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
	printf("tree1 : count = %d depth = %d\n", tree_leavess(bTree), tree_depth(bTree));

	printf("TEST2 : Create btree by pre order\n");
	BiTree preTree = NULL;
	preTree = precreate_btree(show_item_infos, NULL, "root");
	printf("pre: ");
	pre_order(preTree, print_item);
	putchar('\n');
	printf("tree2 : count = %d depth = %d\n", tree_leavess(preTree), tree_depth(preTree));

	printf("TEST3 : fork a tree\n");
	BiTree forkTree;
	forkTree = fork_tree(preTree);
	printf("pre: ");
	pre_order(forkTree, print_item);
	putchar('\n');
	printf("tree3 : count = %d depth = %d\n", tree_leavess(forkTree), tree_depth(forkTree));

	tree_destroy(preTree);
	tree_destroy(bTree);
	tree_destroy(forkTree);

	return 0;
}
