#ifndef __NODE_H__
#define __NODE_H__

struct BinaryTree {
	unsigned char item;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

/* 树的节点 */
typedef struct BinaryTree TreeNode;

/* 树 */
typedef struct BinaryTree * BiTree;
#endif
