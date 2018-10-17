#include <stdio.h>
#include "generics.h"

typedef struct StudentInfo {
	const char *name;
	int score;
}StudentInfo_T, *StudentInfo_P;

/*
 * a is big than b
 */
int cmp_student(void *a, void *b)
{
	return ((StudentInfo_T *)a)->score - ((StudentInfo_T *)b)->score;
}

int main(int argc, char *argv[])
{
	int i;
	StudentInfo_P pMaxScore = NULL;

	StudentInfo_T info_list[4] = {
		{"Tom", 8},
		{"Jerry", 72},
		{"Moby", 90},
		{"Kirby", 89}
	};

	/*
	 * 指针数组
	 * 结构体指针数组
	 */
	StudentInfo_P pInfos[4] = {
		&info_list[0],
		&info_list[1],
		&info_list[2],
		&info_list[3]
	};

	printf("Student's Scores Info:\n");
	for (i = 0; i < 4; i++)
		printf("name %5s : score %5d\n", info_list[i].name, info_list[i].score);

	pMaxScore = get_max_score((void **)pInfos, 4, cmp_student);
	printf("Top score is %s:%d\n", pMaxScore->name, pMaxScore->score);

	return 0;
}
