#include <stdio.h>

#define ELEMENT_NR	10
void bubbleSort(int list[], int size)
{
	int i, j, temp, swap = 1;

	while (swap)
	{
		swap = 0;
		for (i = (size-1) ;i >= 0 ;i--)
		{
			for (j = 1 ; j <= i ;j++ )
			{
				if (list[j-1] > list[j])
				{
					temp = list[j-1];
					list[j-1] = list[j];
					list[j] = temp;
					swap = 1;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int theList[ELEMENT_NR]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int i;

	/* Invoke the bubble sort algorithm */
	bubbleSort(theList, ELEMENT_NR);

	/* Print out the final list */
	for (i = 0 ; i < ELEMENT_NR ; i++)
		printf("%d\t", theList[i]);
	printf("\n");

	return 0;
}
