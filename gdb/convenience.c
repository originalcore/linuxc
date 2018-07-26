#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PEOPLE_NR	10

struct People {
	int age;
	char name[20];
};

int main(int argc, char *argv[])
{
	int i;
	struct People people10[PEOPLE_NR];
	char tmpName[20];

	/* filling peoples */
	for (i = 0; i < PEOPLE_NR; i++)
	{
		people10[i].age = i * 2;
		sprintf(tmpName, "anonymous_%d", i);
		strcpy(people10[i].name, tmpName);
	}

#ifdef __DEBUG__
	for (i = 0; i < PEOPLE_NR; i++)
		printf("%s: age : %d\n", people10[i].name, people10[i].age);
#endif

	return 0;
}
