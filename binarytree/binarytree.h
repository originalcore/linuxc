#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"
struct node* init(unsigned char VLR[], unsigned char LVR[], int n);
void pre_order(struct node *t, void (*visit)(struct node *));
void in_order(struct node *t, void (*visit)(struct node *));
void post_order(struct node *t, void (*visit)(struct node *));
int count(struct node *t);
int depth(struct node *t);
void destroy(struct node *t);
void level_order(struct node *root);

#endif
