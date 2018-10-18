#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILE_NAME "missing.txt"

int main(int argc, char *argv[])
{

	FILE *fin;

	/*
	 * Try to open the file for read
	 * Check for failure to open
	 */
	fin = fopen(FILE_NAME, "r");
	if ((FILE *)0 == fin) {
		/* Emit an error message and exit */
		printf("%s: %s\n", FILE_NAME, strerror(errno));
		exit(-1);
	}

	/* All was well, close the file */
	fclose(fin);
}
