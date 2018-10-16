#include <stdio.h>
#include "binarytree.h"

int main(int argc, char **argv)
{
	printf("Create btree by pre order(421003006500700)\n");
	BiTree preTree = NULL;
	preTree = precreate_btree(show_item_infos, NULL, "root");
	printf("pre: ");
	pre_order(preTree, print_item);
	putchar('\n');
	printf("Tree count = %d depth = %d\n", tree_leavess(preTree), tree_depth(preTree));

	tree_destroy(preTree);

	return 0;
}
