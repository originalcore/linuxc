#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct message {
	void *buf;
	int index;
	char tag[10];
};

int main(int argc, char *argv[])
{
	struct message *m;

	m = malloc(sizeof(struct message));
	if (NULL == m)
	{
		printf("malloc error\n");
		return -1;
	}

	/*
	 * (gdb) set print pretty on
	 * (gdb) p *m
	 * (gdb) p (char *)m->buf
	 */
	m->buf = "abcd";
	m->index = 911;
	strcpy(m->tag, "anonymous");

	free(m);

	return 0;
}
