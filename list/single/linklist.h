#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef unsigned int data_type;

typedef struct list_node {
	data_type item;
	struct list_node *next;
} list_node_t, *list_node_pt;

typedef struct single_list {
	list_node_pt head; /* list head */
	int len; /* length of list nodes */
} single_list_t, *single_list_pt;

single_list_pt create_list(void);
void insert_node_front(single_list_pt list, data_type item);
int show_datas(single_list_pt list);
void delete_node(single_list_pt list, list_node_pt del);
list_node_pt search_node(single_list_pt list, data_type key);
void destory_list(single_list_pt list);
int list_len(single_list_pt list);

#endif

