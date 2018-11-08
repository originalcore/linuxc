#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

typedef unsigned int data_type;
typedef struct list_node {
	data_type data;
	struct list_node *prev;
	struct list_node *next;
} list_node_t, *list_node_pt;

typedef struct double_list {
	list_node_pt head;
	list_node_pt tail;
	int len;
} double_list_t, *double_list_pt;

double_list_pt create_list(void);
void insert_node_front(double_list_pt list, data_type data);
void destory_list(double_list_pt list);
int show_datas(double_list_pt list);
list_node_pt search_node(double_list_pt list, data_type key);
void delete_node(double_list_pt list, list_node_pt p);
int list_len(double_list_pt list);
#endif
