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

#define MAX_OBJECTS	3

MY_TYPE_T objects[MAX_OBJECTS] = {
	{ 0, 1.5, 8.4, "First-object" },
	{ 1, 9.2, 7.4, "Second-object" },
	{ 2, 4.1, 5.6, "Final-object" }
};

int main(int argc, char *argv[])
{
	int i;
	FILE *fout;

	/* Open the output file */
	fout = fopen(FILE_NAME, "w");
	if ((FILE *)0 == fout) {
		/* Emit an error message and exit */
		printf("%s: %s\n", FILE_NAME, strerror(errno));
		exit(-1);
	}

	/* Emit each of the objects, one per line */
	for (i = 0 ; i < MAX_OBJECTS ; i++) {
		fprintf(fout, "%d %f %f %s\n",
				objects[i].id,
				objects[i].x_coord, objects[i].y_coord,
				objects[i].name);
	}

	fclose(fout);

	return 0;
}
