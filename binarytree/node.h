#ifndef __NODE_H__
#define __NODE_H__

typedef unsigned int DataType;
/*
 * TreeNode 表示树节点
 * BitTree表示树
 */
typedef struct BinaryTree {
	unsigned int item;
	struct BinaryTree *left;
	struct BinaryTree *right;
}TreeNode, *BiTree;

void print_item(TreeNode *pTNode);
#endif
