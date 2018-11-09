#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doublylinkedlist.h"

void show_menu(void)
{
	printf("====== Double Link List Test ======\n");
	printf("[m]enu show\n");
	printf("[i]nsert node\n");
	printf("[a]ppend node\n");
	printf("[s]how list\n");
	printf("[x]delete node\n");
	printf("[d]estroy list\n");
	printf("[l]ist len\n");
	printf("[q]uit\n");
	printf("[c]opy list\n");
	printf("=================================\n");
}

char select_menu(void)
{
	char cmd;

	printf("\nEnter Cmd:");
	scanf("%c%*c", &cmd);

	return cmd;
}

int main(int argc, char *argv[])
{
	double_list_pt list = create_list();
	double_list_pt copy;
	data_type data;
	list_node_pt tmp;

	show_menu();
	while (1)
	{
		switch (select_menu())
		{
			case 'm':
				show_menu();
				break;
			case 'i':
				printf("Enter data:");
				scanf("%d%*c", &data);
				insert_node_front(list, data);
				break;
			case 'a':
				printf("Enter data:");
				scanf("%d%*c", &data);
				insert_node_rear(list, data);
				break;
			case 's':
				printf("List:");
				show_datas(list);
				break;
			case 'x':
				printf("Enter node data:");
				scanf("%d%*c", &data);
				tmp = search_node(list, data);
				if (NULL != tmp)
					delete_node(list, tmp);
				else
					printf("Node %d not found\n", data);
				break;
			case 'd':
				destory_list(list);
				break;
			case 'l':
				printf("len = %d\n", list_len(list));
				break;
			case 'q':
				exit(0);
				break;
			case 'c':
				copy = dup_list(list);
				printf("copy list:");
				show_datas(copy);
				break;
			default:
				show_menu();
				break;
		};
	}
}
