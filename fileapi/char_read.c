#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILE_NAME "inpfile.txt"

int main(int argc, char *argv[])
{
	int c;
	FILE *fin;

	fin = fopen(FILE_NAME, "r");
	if ((FILE *)0 == fin) {
		/* Emit an error message and exit */
		printf("%s: %s\n", FILE_NAME, strerror(errno));
		exit(-1);
	}

	do {
		c = fgetc(fin);
		if (c != EOF) {
			printf("%c", (char)c);
		}
	} while (c != EOF);

	fclose(fin);

	return 0;
}
