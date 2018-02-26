#include <stdio.h>

#define MAX_LINE 256
#define TEST_FILE_NAME "digital_file"

/*
 * create a file with 4 number
 * echo "1 2 3 5" > digital_file
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char buf[MAX_LINE];
	int value1, value2;

	file = fopen(TEST_FILE_NAME, "r");
    if (!file)
	{
		printf("Need test file %s\n", TEST_FILE_NAME);
		printf("e.g. echo \"1 2 3 5\" > digital_file\n");
		return 1;
	}

	/* read the file context and close */
    fgets(buf, MAX_LINE, file);
    fclose(file);

	/* e.g. skip the first and second value */
	sscanf(buf, "%*d %*d %d %d", &value1, &value2);
	printf("v1 = %d, v2 = %d\n", value1, value2);

	/* e.g. skip the second input */
	printf("Input three numbers:");
	scanf("%d %*d %d", &value1, &value2);
	printf("v1 = %d, v3 = %d\n", value1, value2);

	return 0;
}
