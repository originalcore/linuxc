#include <stdio.h>
#include "binarytree.h"

int main(int argc, char **argv)
{
	BiTree bstTree;
	int array[] = {4, 1, 5, 3, 7, 6, 2};

	printf("Binary Search Tree Test\n");
	bstTree = create_bst(array, 7);
	printf("pre: ");
	pre_order(bstTree, print_item);
	putchar('\n');
	printf("Tree count = %d depth = %d\n", tree_leavess(bstTree), tree_depth(bstTree));
	printf("level: ");
	level_order(bstTree);
	putchar('\n');

	tree_destroy(bstTree);

	return 0;
}
