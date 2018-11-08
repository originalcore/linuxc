#include <stdlib.h>
#include "doublylinkedlist.h"
#include <stdio.h>
#include <assert.h>

double_list_pt create_list(void)
{
	double_list_pt list;

	/*
	 * sentinel node is not a valid node
	 * data = 0 means invalid
	 */
	list_node_pt headsentinel;
	list_node_pt tailsentinel;

	headsentinel = malloc(sizeof(list_node_t));
	if (NULL == headsentinel)
		return NULL;
	tailsentinel = malloc(sizeof(list_node_t));
	if (NULL == tailsentinel)
		return NULL;

	headsentinel->data = 0;
	headsentinel->prev = NULL;
	headsentinel->next = tailsentinel;
	tailsentinel->data = 0;
	tailsentinel->prev = headsentinel;
	tailsentinel->next = NULL;

	/* the real list */
	list = malloc(sizeof(double_list_t));
	if (NULL == list)
		return NULL;

	/* init list head, tail and len */
	list->head = headsentinel;
	list->tail = tailsentinel;
	list->len = 0;

	return list;
}

static list_node_pt make_node(data_type data)
{
	list_node_pt pnode = NULL;

	pnode = malloc(sizeof(list_node_t));
	if (NULL == pnode)
		return NULL;

	pnode->data = data;
	pnode->prev = NULL;
	pnode->next = NULL;

	return pnode;
}

/* insert node in the front of the list */
void insert_node_front(double_list_pt list, data_type data)
{
	list_node_pt head = list->head;
	list_node_pt pnode = make_node(data);

	pnode->next = head->next;
	head->next->prev = pnode;
	head->next = pnode;
	pnode->prev = head;

	list->len++;
}

/* append node in the rear of the list */
void insert_node_rear(double_list_pt list, data_type data)
{
	list_node_pt tail = list->tail;
	list_node_pt pnode = make_node(data);

	pnode->prev = tail->prev;
	tail->prev->next = pnode;
	tail->prev = pnode;
	pnode->next = tail;

	list->len++;
}

/*
 * @visit is a function pointer
 * return void *
 * takes three arguments: double_list_pt, list_node_pt, void *
 *
 * return value of visit varies from the real implement
 */
static void *traverse(double_list_pt list,
		void *(*visit) (double_list_pt, list_node_pt, void *), void *ptr)
{
	/* the first valid node */
	list_node_pt pnode = list->head->next;
	void *ret;

	while (pnode != list->tail)
	{
		/*
		 * there's no necessary to iterator list anymore
		 * while some visit function calls return not NULL
		 * so just break the loop
		 */
		ret = visit(list, pnode, ptr);
		if (ret != NULL)
			break;
		pnode = pnode->next;
	}

	return ret;
}

/*
 * dont't care about the return value
 * so return NULL means success
 */
static void *print_data(double_list_pt list, list_node_pt pnode, void *ptr)
{
	printf("%d ", pnode->data);
	return NULL;
}

/*
 * free node memeory space and decrement list len
 *
 * dont't care about the return value
 * so return NULL means success
 */
static void *free_node(double_list_pt list, list_node_pt pnode, void *ptr)
{
	free(pnode);
	pnode = NULL;
	list->len--;

	return NULL;
}

/*
 * In link list compare the pnode value with key
 *
 * return NULL means failed to search
 * return node when success
 */
static void *compare_node(double_list_pt list, list_node_pt pnode, void *key)
{
	/* yes, return the match node */
	if (pnode->data == *(data_type *)key)
		return (void *)pnode;

	/* no this node found */
	return NULL;
}

void destory_list(double_list_pt list)
{
	/* free valid node memory */
	traverse(list, free_node, NULL);

	/* free sentinel and list */
	free(list->head);
	free(list->tail);
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
	free(list);
	list = NULL;
}

int show_datas(double_list_pt list)
{
	if (0 == list->len)
	{
		printf("Empty Link list\n");
		return 1;
	}
	traverse(list, print_data, NULL);
	printf("\n");
	return 0;
}

/* match the node with compare_node function */
list_node_pt search_node(double_list_pt list, data_type key)
{
	return (list_node_pt)traverse(list, compare_node, &key);
}

/* delete pnode from the list */
void delete_node(double_list_pt list, list_node_pt pnode)
{
	list_node_pt del;

	assert(NULL != pnode);
	del = search_node(list, pnode->data);
	if (NULL == del)
	{
		printf("Node %d not found\n", pnode->data);
		return;
	}

	del->prev->next = del->next;
	del->next->prev = del->prev;
	free_node(list, del, NULL);
}

int list_len(double_list_pt list)
{
	return list->len;
}

/* duplicate a list */
double_list_pt dup_list(double_list_pt orig_list)
{
	/* fetch the first valid node */
	list_node_pt current = orig_list->head->next;
	list_node_pt tail = orig_list->tail;
	double_list_pt copy_list;

	copy_list = create_list();
	while (current != tail)
	{
		insert_node_rear(copy_list, current->data);
		current = current->next;
	}

	return copy_list;
}
