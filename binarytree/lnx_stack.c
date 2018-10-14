#include <stdio.h>

#define LEN 1024
static struct node *lnx_stack[LEN];

/* 栈顶指针,指向空数据的位置,即栈顶元素的下一个位置 */
static int stack_top = 0;
/*
 *    +-------------+
 *    |	data1		|
 *    +-------------+
 *    |	data2		|
 *    +-------------+
 *    |				| <---stack_top
 *    +-------------+
 *    |				|
 *    +-------------+
 */

void lnx_stack_push(struct node *item)
{
	lnx_stack[stack_top++] = item;
}

/* 因为栈顶指针指向的是空数据的位置,所以是前减减 */
struct node *lnx_stack_pop(void)
{
	return lnx_stack[--stack_top];
}

int lnx_stack_is_empty(void)
{
	return stack_top == 0;
}

/* 返回栈顶元素 */
struct node *lnx_stack_peek(void)
{
	return lnx_stack[stack_top - 1];
}
