#include <stdlib.h>
#include <assert.h>
#include "lnx_queue.h"
#include "binarytree.h"

/*
 * 哨岗(sentinel), 数据域中不存储实际数据
 * next和prev指针初始都指向自己
 *
 * 引入哨岗的目的是因为在insert和
 * delete的时候会有一些特殊情况
 * 需要用特殊代码处理,不能和一般
 * 情况用同样的代码,添加这个哨岗
 * 就能将这些特殊情况转化为一般情况
 */
struct lnx_queue_node sentinel;
struct lnx_queue_node sentinel = {0, &sentinel, &sentinel};

static struct lnx_queue_node *head = &sentinel;

static struct lnx_queue_node* make_lnx_queue_node(struct node *np)
{
	struct lnx_queue_node *p = NULL;

	p = malloc(sizeof(struct lnx_queue_node));
	p->np = np;
	p->prev = NULL;
	p->next = NULL;

	return p;
}

void free_lnx_queue_node(struct lnx_queue_node *p)
{
	free(p);
}

static void lnx_queue_insert(struct lnx_queue_node* p)
{
	p->next = head->next;
	head->next->prev = p;

	/*
	 * head的next指向新插入的lnx_queue_node
	 * 这是个前插操作
	 * head->Pn->Pn-1...->P2->P1
	 */
	head->next = p;
	p->prev = head;
}

static void delete(struct lnx_queue_node* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

void lnx_queue_enqueue(struct node *pn)
{
	struct lnx_queue_node *p;

	p = make_lnx_queue_node(pn);
	lnx_queue_insert(p);
}

/* 尾部出列 */
struct lnx_queue_node* lnx_queue_dequeue(void)
{
	/* 空链表 */
	if (head->prev == head)
		return NULL;
	else
	{
		struct lnx_queue_node *p = head->prev;
		delete(p);
		return p;
	}
}

/* 从head的next开始遍历 */
void lnx_queue_traverse(void (*visit) (struct lnx_queue_node*))
{
	struct lnx_queue_node *p;

	for (p = head->next; p != head; p = p->next)
		visit(p);
}

int lnx_queue_is_empty(void)
{
	return head->next == &sentinel;
}
