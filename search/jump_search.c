#include <stdio.h>
#include <math.h>

#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

/*
 * Find key in array, array must be sorted
 * Success : return the index in array
 * Failed : return -1
 *
 * 算法原理:
 * 1. 最佳step = len开平方, 所以时间复杂度是O(len开平方)
 * 2. 数组array将分成 len / step 个区间
 * array[0]...array[step-1]...array[2 * step - 1]...
 *
 * 3. 需要查找的key必位于区间[m * step, (m+1) * step]中
 * array[m * step] < key < array[(m+1) * step]
 *
 * 4. 找到上面的区间后, 就能够从区间m*step开始线性查找
 *
 * 算法总结:
 * 时间复杂度线性搜索O(n)
 * 跳跃搜索O(n开平方)
 * 二分法查找O(log n)
 * O(n) < O(n开平方) < O(log n)
 */
int jump_search(int array[], int len, int key)
{
	/* jump step, 跳跃间隔 */
	int step;

	/* previous jump section, start from 0 */
	int prev = 0;

	/* find the best step, 跳跃间隔的最佳值 */
	step = floor(sqrt(len));

	/*
	 * 找到小于key的最大左区间值
	 * 循环结束后
	 * prev保存最大左区间
	 * step保存最小右区间
	 */
	while (*(array + (MIN(step, len) - 1)) < key)
	{
		/* save current step section */
		prev = step;

		/* goto the next section */
		step += floor(sqrt(len));

		/* outof range, must not happen */
		if (prev >= len)
			return -1;
	}
	printf("key should in array[%d] ~ array[%d]\n", prev, step);

	/* 线性查找区间[m * step, (m+1) * step] */
	while (*(array + prev) < key)
	{
		prev++; /* 顺序查找 */

		/* key not found */
		if (prev == fmin(step, len))
			return -1;
	}

	/* check value */
	if (*(array + prev) == key)
		return prev;

	/* key not found */
	return -1;
}

/*
 * Usage:
 * gcc % -lm
 */
int main(int argc, char *argv[])
{
	int data[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};

	int key; /* find this */
	int index;
	int len;
	int i;

	len = ARRAY_LEN(data);
	for (i = 0; i < len; i++)
		printf("%d ", data[i]);
	printf("\n");

	printf("Enter a key :");
	scanf("%d", &key);
	index = jump_search(data, len,  key);
	if (!index)
		printf("key not found\n");

	printf("%d == array[%d]\n", key, index);

	return 0;
}
