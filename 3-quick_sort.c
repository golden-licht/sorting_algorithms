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
	static int count;
	int pivot, j, i = 0;

	if (size <= 1)
		return;
	pivot = size - 1;
	/* just to make sure original array is not updated on successive calls */
	if (count == 0)
	{
		original_array = array;
		original_size = size;
	}
	count++;

	for (j = 0, i = j - 1; j < pivot; j++)
	{
		if (array[j] < array[pivot])
		{
			i++;
			/* swap only if i != j */
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(original_array, original_size);
			}
		}
	}
	i++;
	/* swap only if i != pivot */
	if (i != pivot)
	{
		swap_int(&array[i], &array[pivot]);
		print_array(original_array, original_size);
	}
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

