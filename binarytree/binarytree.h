#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"
BiTree init(unsigned char VLR[], unsigned char LVR[], int n);
void pre_order(BiTree bTree, void(*visit)(TreeNode *));
void in_order(BiTree bTree, void(*visit)(TreeNode *));
void post_order(BiTree bTree, void(*visit)(TreeNode *));
int tree_leavess(BiTree bTree);
int tree_depth(BiTree bTree);
void tree_destroy(BiTree bTree);
void level_order(BiTree bTree);
void pre_order_nonrecursion(TreeNode *pTNode);
void in_order_nonrecursion(TreeNode *pTNode);
void post_order_nonrecursion(TreeNode *pTNode);
BiTree precreate_btree(void (*prompt)(TreeNode *, const char *child), TreeNode *parent, const char *msg);
void show_item_infos(TreeNode *pTNode, const char *msg);
#endif
