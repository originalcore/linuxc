#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"
#include "menu.h"

int main(int argc, char *argv[])
{
	single_list_pt list = NULL;
	data_type data;
	list_node_pt tmp;

	list = create_list();

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
			case 'l':
				printf("len = %d\n", list_len(list));
				break;
			case 'q':
				exit(0);
				break;
			case 'd':
				destory_list(list);
				break;
			default:
				show_menu();
				break;
		};
	}

	return 0;
}
