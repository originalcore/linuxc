#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "linklist.h"

single_list_pt create_list(void)
{
	single_list_pt list = NULL;

	list = malloc(sizeof(single_list_pt));
	if (NULL == list)
		return NULL;

	list->head = NULL;
	list->len = 0;

	return list;
}

static list_node_pt make_node(data_type item)
{
	list_node_pt p = NULL;

	p = malloc(sizeof(list_node_t));
	if (NULL == p)
		return NULL;

	p->item = item;
	p->next = NULL;

	return p;
}

/* 在(空)链表前面插入 */
void insert_node_front(single_list_pt list, data_type item)
{
	list_node_pt p;

	p = make_node(item);
	assert(NULL != p);

	p->next = list->head;
	list->head = p;
	list->len++;
}

/*
 * 遍历链表
 * 这个函数设计很巧秒
 * 用函数指针作为参数
 * 根据传进来的函数指针不同,这个函数就有不同的作用
 */
void traverse(single_list_pt list, void (*visit)(list_node_pt))
{
	list_node_pt p;
	list_node_pt head = list->head;

	for (p = head; p; p = p->next)
		visit(p);
}

static void print_data(list_node_pt pnode)
{
	printf("%d ", pnode->item);
}

int show_datas(single_list_pt list)
{
	if (0 == list->len)
	{
		printf("Empty Link list\n");
		return 1;
	}

	traverse(list, print_data);
	printf("\n");

	return 0;
}

list_node_pt search_node(single_list_pt list, data_type key)
{
	list_node_pt p = NULL;
	list_node_pt head = list->head;

	/*
	 * 隐含了对于空链表这种特殊情况的处理,
	 * 如果是空链表则循环体一次都不执行,直接返回NULL
	 */
	for (p = head; p; p = p->next)
		if (p->item == key)
			return p;

	return NULL;
}

static void free_node(single_list_pt list, list_node_pt pnode)
{
	free(pnode);
	pnode = NULL;
	list->len--;
}

/*
 * 优化版本
 * 不需要对是否是删除头部特殊判断
 * 这里巧用了二级指针操作
 * 一个指向当前节点的二级指针就是其上一节点
 */
void delete_node(single_list_pt list, list_node_pt del)
{
	list_node_pt *pnext;

	for (pnext = &(list->head); *pnext; pnext = &(*pnext)->next)
	{
		if (*pnext == del)
		{
			*pnext = del->next;
			free_node(list, del);
			return;
		}
	}
}

void destory_list(single_list_pt list)
{
	list_node_pt p = list->head;
	list_node_pt q;

	while (p)
	{
		q = p;
		p = p->next;
		free_node(list, q);
	}
}

int list_len(single_list_pt list)
{
	return list->len;
}
