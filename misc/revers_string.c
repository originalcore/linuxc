#include <stdio.h>
#include <string.h>

#undef DBG_PRINT

#ifdef DBG_PRINT
#define dbg_print	printf
#else
#define dbg_print
#endif
void rever(char *str)
{
	char *head;
	char *tail;
	int len;

	len = strlen(str);
	dbg_print("len = %d\n", len);

	head = str;
	tail = str + len - 1;

	dbg_print("%p, %p, %d\n", head, tail, tail - head);
	while (head < tail)
	{
		dbg_print("head = %p[%c], tail = %p[%c], %d\n", head, *head,  tail, *tail, tail - head);
		*head ^= *tail;
		*tail ^= *head ;
		*head ^= *tail;

		dbg_print("head = %p[%c], tail = %p[%c], %d\n", head, *head,  tail, *tail, tail - head);
		head++;
		tail--;
	}

	dbg_print("%s\n", str);
}

int main(int argc, char **argv)
{
	char *str = NULL;
	int len;

	if (argc < 2)
	{
		printf("%s <string>\n", argv[0]);
		return -1;
	}

	len = strlen(argv[1]);
	str = (char *)malloc(sizeof(char) * len);
	if (NULL == str)
	{
		printf("malloc error\n");
		return -2;
	}

	strncpy(str, argv[1], len);

	printf("Org:%s\n", str);
	rever(str);
	printf("Rev:%s\n", str);

	free(str);

	return 0;
}
