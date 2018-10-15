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
QueueNode sentinel;
QueueNode sentinel = {0, &sentinel, &sentinel};

static QueueNode *head = &sentinel;

static QueueNode* make_lnx_queue_node(TreeNode *pTNode)
{
	QueueNode *pQNode = NULL;

	pQNode = malloc(sizeof(QueueNode));
	pQNode->tree_node = pTNode;
	pQNode->prev = NULL;
	pQNode->next = NULL;

	return pQNode;
}

void free_lnx_queue_node(QueueNode *pQNode)
{
	free(pQNode);
}

static void lnx_queue_insert(QueueNode *pQNode)
{
	pQNode->next = head->next;
	head->next->prev = pQNode;

	/*
	 * head的next指向新插入的lnx_queue_node
	 * 这是个前插操作
	 * head->Pn->Pn-1...->P2->P1
	 */
	head->next = pQNode;
	pQNode->prev = head;
}

static void delete(QueueNode* pQNode)
{
	pQNode->prev->next = pQNode->next;
	pQNode->next->prev = pQNode->prev;
}

void lnx_queue_enqueue(TreeNode *pTNode)
{
	QueueNode *pQNode;

	pQNode = make_lnx_queue_node(pTNode);
	lnx_queue_insert(pQNode);
}

/* 尾部出列 */
QueueNode* lnx_queue_dequeue(void)
{
	/* 空链表 */
	if (head->prev == head)
		return NULL;
	else
	{
		QueueNode *pQNode = head->prev;
		delete(pQNode);
		return pQNode;
	}
}

/* 从head的next开始遍历 */
void lnx_queue_traverse(void (*visit) (QueueNode*))
{
	QueueNode *pQNode;

	for (pQNode = head->next; pQNode != head; pQNode = pQNode->next)
		visit(pQNode);
}

int lnx_queue_is_empty(void)
{
	return head->next == &sentinel;
}
