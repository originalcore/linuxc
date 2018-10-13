#ifndef __COMMON_H__
#define __COMMON_H__
#include <stdio.h>
#include "binarytree.h"
void print_item(struct node *p)
{
	printf("%d", p->item);
}
#endif
