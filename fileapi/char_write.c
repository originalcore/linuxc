#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILE_NAME "inpfile.txt"

int main(int argc, char *argv[])
{
	int i = 0;
	FILE *fout;
	const char string[] = {"This\r\nis a test\r\nfile.\r\n\0"};

	fout = fopen(FILE_NAME, "w");
	if ((FILE *)0 == fout) {
		/* Emit an error message and exit */
		printf("%s: %s\n", FILE_NAME, strerror(errno));
		exit(-1);
	}

	while (string[i] != 0) {
		fputc((int)string[i], fout);
		i++;
	}

	fclose(fout);

	return 0;
}
