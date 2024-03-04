#include <stdbool.h>

#include "sort.h"

/**
 * selection_sort - Sort an array of integers using selection sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		size_t current_smallest_index = i;
		size_t j;
		bool swapped = false;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[current_smallest_index])
			{
				current_smallest_index = j;
				swapped = true;
			}
		}

		if (swapped)
		{
			swap_int(&array[i], &array[current_smallest_index]);
			print_array(array, size);
		}
	}
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
