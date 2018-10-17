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
BiTree fork_tree(BiTree bTree);
TreeNode *find_node(BiTree bTree, DataType item);
void show_item_infos(TreeNode *pTNode, const char *msg);
int level_of_leaf(BiTree bTree, TreeNode *pTNode);
BiTree create_bst(int array[], int len);
TreeNode *bst_find_min(BiTree bTree);
TreeNode *bst_find_max(BiTree bTree);
TreeNode *bst_find_node(BiTree bTree, DataType data);
TreeNode *bst_find_node_nonrecursion(BiTree bTree, DataType data);
BiTree bst_delete_node(BiTree *pbTree, DataType data);
#endif
