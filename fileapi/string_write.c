#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define FILE_NAME "testfile.txt"

#define LEN	80

int main(int argc, char *argv[])
{
	char line[LEN+1];
	FILE *fout, *fin;

	fout = fopen(FILE_NAME, "w");
	if ((FILE *)0 == fout) {
		/* Emit an error message and exit */
		printf("%s: %s\n", FILE_NAME, strerror(errno));
		exit(-1);
	}

	/*
	 * stdin 是FILE * 类型
	 * STDIN_FILENO 是fd类型
	 * STDIN_FILENO = fileno(stdin)
	 */
	fin = fdopen(STDIN_FILENO, "r");

	/* Ctrl-d in terminal means EOF */
	while ((fgets(line, LEN, fin)) != NULL) {
		fputs(line, fout);
	}

	fclose(fout);
	fclose(fin);

	return 0;
}
