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
	FILE *fin;

	fin = fopen(FILE_NAME, "r" );
	if ((FILE *)0 == fin) {
		/* Emit an error message and exit */
		printf("%s: %s\n", FILE_NAME, strerror(errno));
		exit(-1);
	}

	while ((fgets(line, LEN, fin)) != NULL) {
		printf("%s", line);
	}

	fclose(fin);

	return 0;
}
