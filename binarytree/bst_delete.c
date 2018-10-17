#include <stdio.h>
#include "binarytree.h"

int main(int argc, char *argv[])
{
	BiTree bstTree;
	int array[] = {17, 12, 19, 10, 15, 18, 25, 8, 11, 13, 16, 22};

	printf("Binary Search Tree Test\n");
	bstTree = create_bst(array, 12);
	printf("pre: ");
	pre_order(bstTree, print_item);
	putchar('\n');
	printf("Tree count = %d depth = %d\n", tree_leavess(bstTree), tree_depth(bstTree));
	printf("level: ");
	level_order(bstTree);
	putchar('\n');

	printf("Delete node 12\n");
	bstTree = bst_delete_node(&bstTree, 12);
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
