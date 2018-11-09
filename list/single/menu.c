#include <stdio.h>

void show_menu(void)
{
	printf("====== Link List Test ======\n");
	printf("[m]enu show\n");
	printf("[i]nsert node\n");
	printf("[s]how list\n");
	printf("[x]delete node\n");
	printf("[d]estroy list\n");
	printf("[l]ist len\n");
	printf("[q]uit\n");
	printf("=============================\n");
}

char select_menu(void)
{
	char cmd;

	printf("\nEnter Cmd:");
	scanf("%c%*c", &cmd);

	return cmd;
}
