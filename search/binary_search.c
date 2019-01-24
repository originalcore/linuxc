#include <stdio.h>

#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))

/* recursive version */
int binarysearch_r(int array[], int left, int right, int key)
{
	int mid;

	if (right >= left)
	{
		mid = (left + right) / 2;

		/* element is present at middle */
		if (array[mid] == key)
			return mid;

		/* element is greater than middle */
		if (array[mid] < key)
			return binarysearch_r(array, mid + 1, right, key);
		else /* element is in left subarray */
			return binarysearch_r(array, left, mid - 1, key);
	}

	/* element is not present in array */
	return -1;
}

/* normal version */
int binarysearch_n(int array[], int len, int key)
{
	int mid;
	int i;
	int left;
	int right;

	left = 0;
	right = len;

	for (i = 0; i < len; i++)
	{
		mid = (left + right) / 2;

		/* element is present at middle */
		if (array[mid] == key)
			return mid;

		/* element is greater than middle */
		if (array[mid] < key)
			left = mid + 1;
		else /* element is in left subarray */
			right = mid - 1;
	}

	/* element is not present in array */
	return -1;
}

int main(int argc, char *argv[])
{
	int i;
	int index;
	int len;
	int key;

	int data[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};

	len = ARRAY_LEN(data);

	for (i = 0; i < len; i++)
		printf("%d ", data[i]);
	printf("\n");

	printf("Enter key : ");
	scanf("%d", &key);
	index = binarysearch_r(data, 0, len - 1, key);
	if (index < 0)
	{
		printf("Key not found\n");
		return -1;
	}
	printf("key = array[%d]\n", index);

	index = binarysearch_n(data, len, key);
	if (index < 0)
	{
		printf("Key not found\n");
		return -1;
	}
	printf("key = array[%d]\n", index);

	return 0;
}
