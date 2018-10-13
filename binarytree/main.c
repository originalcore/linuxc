#include <stdio.h>
#include "binarytree.h"
#include "common.h"

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

	struct node * root = init(pre_seq, in_seq, 7);

	printf("pre: ");
	pre_order(root, print_item);
	putchar('\n');

	printf("in: ");
	in_order(root, print_item);
	putchar('\n');

	printf("post: ");
	post_order(root, print_item);
	putchar('\n');

	printf("level: ");
	level_order(root);
	putchar('\n');

	printf("count=%d depth=%d\n", count(root), depth(root));

	destroy(root);

	return 0;
}
