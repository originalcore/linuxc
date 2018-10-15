/*
 * Usage: gcc -DDEBUG inset_sort.c
 */

#include <stdio.h>

int arr[] = {53, 27, 36, 15, 69, 42};

void show_array(int array[], int len, int key_index)
{
	int i;

	if (0 != key_index)
		printf("[");

	for (i = 0; i < len; i++)
	{
		if (i == key_index && key_index > 0)
		{
			printf("(%d)\t", array[i]);
			continue;
		}
		if (i == key_index - 1)
		{
			printf("%d]\t", array[i]);
			continue;
		}
		else
			printf("%d\t", array[i]);
	}
	printf("\n");
}

void insert_sort(int arr[], int len)
{
	int i, j, key;

	/* 从第一个数开始遍历 */
	for (j = 1; j < len; j++)
	{
		/* 保存每次遍历的这个数,作为比较数 */
		key = arr[j];
#ifdef DEBUG
		if (j == 1)
			show_array(arr, len, j);
#endif

		/*
		* 从最开始取数和子序列比较(i = j - 1)
		* 如果满足条件,进行交换
		*/
		for (i = j - 1; i >= 0 && arr[i] > key; i--)
			arr[i + 1] = arr[i];

		arr[i + 1] = key;
#ifdef DEBUG
		show_array(arr, len, j + 1);
#endif
	}
}

int main(int argc, char **argv)
{
	int len = sizeof(arr) / sizeof(arr[0]);
	insert_sort(arr, len);
	return 0;
}
