#ifndef __NODE_H__
#define __NODE_H__

struct node {
	unsigned char item;
	struct node *left;
	struct node *right;
};

#endif
