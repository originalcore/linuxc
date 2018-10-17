#include <stdio.h>
#include "generics.h"

/*
 * 利用cmp比较规则来比较data里的数据
 * 取出按照设定规则较大的值
 *
 * 获取尖子生的信息
 */
void *get_max_score(void *data[], int num, cmp_t cmp)
{
	int i;
	void *top_student = data[0];

	for (i = 1; i < num; i++)
		if (cmp(data[i], top_student) > 0)
			top_student = data[i];

	return top_student;
}
