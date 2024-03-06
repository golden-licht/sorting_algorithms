#include "sort.h"

/**
 * quick_sort - sorts an array of integers using the Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	static int *original_array;
	static size_t original_size;
	int pivot, j, i = 0;

	pivot = size - 1;
	original_array = NULL;
	original_size = 0;

	if (size <= 1)
		return;
	if (original_array == NULL)
	{
		original_array = array;
		original_size = size;
	}
	for (j = 0, i = j - 1; j < pivot; j++)
	{
		if (array[j] < array[pivot])
		{
			i++;
			swap_int(&array[i], &array[j]);
		}
	}
	i++;
	swap_int(&array[i], &array[pivot]);
	print_array(original_array, original_size);
	quick_sort(array, i);
	quick_sort(array + i + 1, size - i - 1);
}

/**
 * swap_int - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
*/
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

