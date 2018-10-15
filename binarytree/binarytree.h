#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"
BiTree init(unsigned char VLR[], unsigned char LVR[], int n);
void pre_order(TreeNode *pTNode, void(*visit)(TreeNode *));
void in_order(TreeNode *pTNode, void(*visit)(TreeNode *));
void post_order(TreeNode *pTNode, void(*visit)(TreeNode *));
int count(TreeNode *pTNode);
int depth(TreeNode *pTNode);
void destroy(BiTree bTree);
void level_order(BiTree bTree);
void pre_order_nonrecursion(TreeNode *pTNode);
void in_order_nonrecursion(TreeNode *pTNode);
void post_order_nonrecursion(TreeNode *pTNode);
#endif
