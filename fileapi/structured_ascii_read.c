#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE	40

#define FILE_NAME "myfile.txt"

typedef struct {
	int id;
	float x_coord;
	float y_coord;
	char name[MAX_LINE+1];
} MY_TYPE_T;

MY_TYPE_T object;

int main(int argc, char *argv[])
{
	FILE *fin;

	/* Open the input file */
	fin = fopen(FILE_NAME, "r");
	if ((FILE *)0 == fin) {
		/* Emit an error message and exit */
		printf("%s: %s\n", FILE_NAME, strerror(errno));
		exit(-1);
	}

	/* Read the records from the file and emit */
	while (!feof(fin)) {
		fscanf(fin, "%d %f %f %s\n",
				&object.id,
				&object.x_coord, &object.y_coord,
				object.name);

		printf("%d %f %f %s\n",
				object.id,
				object.x_coord, object.y_coord,
				object.name);
	}

	fclose(fin);

	return 0;
}
