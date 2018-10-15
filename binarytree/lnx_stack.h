#ifndef __LNX_STACK__
#define __LNX_STACK__
#include "node.h"

void lnx_stack_push(TreeNode *pTNode);
TreeNode *lnx_stack_pop(void);
int lnx_stack_is_empty(void);
TreeNode *lnx_stack_peek(void);
#endif
