#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doublylinkedlist.h"

void show_menu(void)
{
	printf("====== Double Link List Test ======\n");
	printf("1 insert node\n");
	printf("2 show list\n");
	printf("3 delete node\n");
	printf("4 destroy list\n");
	printf("5 list len\n");
	printf("6 exit\n");
	printf("=================================\n");
}

int select_menu(void)
{
	int cmd;

	show_menu();
	printf("\nEnter Cmd:");
	scanf("%d%*c", &cmd);
	assert(cmd > 0);
	assert(cmd < 9);
	return cmd;
}

int main(int argc, char *argv[])
{
	double_list_pt list = create_list();
	data_type data;
	list_node_pt tmp;

	while (1)
	{
		switch (select_menu())
		{
			case 1:
				printf("Enter data:");
				scanf("%d", &data);
				insert_node_front(list, data);
				break;
			case 2:
				printf("List:");
				show_datas(list);
				break;
			case 3:
				printf("Enter node data:");
				scanf("%d", &data);
				tmp = search_node(list, data);
				delete_node(list, tmp);
				break;
			case 4:
				destory_list(list);
				break;
			case 5:
				printf("len = %d\n", list_len(list));
				break;
			case 6:
				exit(0);
				break;
			default:
				break;
		};
	}
}
