#include <stdio.h>

#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))

typedef int ElementType;

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
 * Return medianof left, center, right
 *
 * @left : lowest index of array
 * @right : highest index of array
 * return pivot value
 */
ElementType median3(ElementType array[], int left, int right)
{
	int center = (left + right) / 2;

	/* Invariant: array[left] <= array[center] <= array[right] */
	if (array[left] > array[center])
		swap(&array[left], &array[center]);
	if (array[left] > array[right])
		swap(&array[left], &array[right]);
	if (array[center] > array[right])
		swap(&array[center], &array[right]);

	return array[center];
}

/* return pivot index */
int partition(ElementType array[], int left, int right, ElementType pivot)
{
	int i, j;

	/* partiton S1 < pivot < S2 */
	i = left;
	j = right;
	for (;;)
	{
		while (array[++i] < pivot);
		while (array[--j] > pivot);
		if (i < j)
			swap(&array[i], &array[j]);
		else
			break;
	}

	return i;
}

/*
 * @array : array ready to be sort, call it S for short
 * @left : lowest index of array
 * @right : highest index of array
 */
void quick_sort(ElementType array[], int left, int right)
{
	int k;
	ElementType pivot;

	if (left < right)
	{
		/*
		 * figure out the pivot
		 * there are two recommand way to find pivot
		 * 1. using random pivot in the S
		 * 2. using median in the (S[left], S[center], S[right])
		 */
		pivot = median3(array, left, right);

		/* S1 < pivot < S2 */
		k = partition(array, left, right, pivot);

		/* sort S1 */
		quick_sort(array, left, k - 1);

		/* sort pivot + S2 */
		quick_sort(array, k, right);
	}
}

void show_array(ElementType array[], int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	int len;
	ElementType A[] = {3, 12, 32, 1, 2, 33, 78, 21};


	len = ARRAY_LEN(A);
	show_array(A, len);
	quick_sort(A, 0, len - 1);
	show_array(A, len);

	return 0;
}
