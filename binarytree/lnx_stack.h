#ifndef __LNX_STACK__
#define __LNX_STACK__
void lnx_stack_push(struct node *item);
struct node *lnx_stack_pop(void);
int lnx_stack_is_empty(void);
struct node *lnx_stack_peek(void);
#endif
