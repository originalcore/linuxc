#include <stdio.h>
#include "binarytree.h"

int main(int argc, char **argv)
{
	BiTree bstTree;
	TreeNode *min_max;
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

	min_max = bst_find_min(bstTree);
	printf("min node is %d\n", min_max->item);
	min_max = bst_find_max(bstTree);
	printf("max node is %d\n", min_max->item);

	printf("find node 1, 3, 7, 9\n");
	DataType find_this[] = {1, 3, 7, 9};
	TreeNode *pTNode;
	int i;
	for (i = 0; i < sizeof(find_this) / sizeof(find_this[0]); i++)
	{
		pTNode = bst_find_node(bstTree, find_this[i]);
		if (pTNode)
			printf("Node %d found\n", pTNode->item);
		else
			printf("Node %d ain't exist\n", find_this[i]);
	}

	for (i = 0; i < sizeof(find_this) / sizeof(find_this[0]); i++)
	{
		pTNode = bst_find_node_nonrecursion(bstTree, find_this[i]);
		if (pTNode)
			printf("Node %d found\n", pTNode->item);
		else
			printf("Node %d ain't exist\n", find_this[i]);
	}

	tree_destroy(bstTree);

	return 0;
}
