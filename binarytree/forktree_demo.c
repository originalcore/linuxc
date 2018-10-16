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

	printf("Fork a tree\n");
	BiTree forkTree;
	forkTree = fork_tree(bTree);
	printf("pre: ");
	pre_order(forkTree, print_item);
	putchar('\n');
	printf("Tree count = %d depth = %d\n", tree_leavess(forkTree), tree_depth(forkTree));

	tree_destroy(bTree);
	tree_destroy(forkTree);

	return 0;
}
