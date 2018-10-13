#include <stdlib.h>
#include <assert.h>
#include "lnx_queue.h"

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
struct node sentinel;
struct node sentinel = {0, &sentinel, &sentinel};

static struct node *head = &sentinel;

struct node* make_node(unsigned char item)
{
	struct node *p = NULL;

	p = malloc(sizeof(struct node));
	p->item = item;
	p->prev = NULL;
	p->next = NULL;

	return p;
}

void free_node(struct node *p)
{
	free(p);
}

static void insert(struct node* p)
{
	p->next = head->next;
	head->next->prev = p;

	/*
	 * head的next指向新插入的node
	 * 这是个前插操作
	 * head->Pn->Pn-1...->P2->P1
	 */
	head->next = p;
	p->prev = head;
}

static void delete(struct node* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

/* deep free the node q */
void destroy(struct node *q)
{
	struct node *p = head->next;

	head->next = head;
	head->prev = head;

	while (p != head)
	{
		q = p;
		p = p->next;
		free_node(q);
	}
}

void enqueue(struct node *p)
{
	insert(p);
}

/* 尾部出列 */
struct node* dequeue(void)
{
	/* 空链表 */
	if (head->prev == head)
		return NULL;
	else
	{
		struct node *p = head->prev;
		delete(p);
		return p;
	}
}

/* 从head的next开始遍历 */
void traverse(void (*visit) (struct node*))
{
	struct node *p;

	for (p = head->next; p != head; p = p->next)
		visit(p);
}

int is_empty(void)
{
	return head->next == &sentinel;
}
