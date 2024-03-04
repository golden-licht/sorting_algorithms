#include <stdbool.h>

#include "sort.h"

/**
 * bubble_sort - Sort an array of integers using bubble sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t indexing_length = size - 1;
	bool swapped = true;

	if (array == NULL || size < 2)
		return;

	while (swapped && indexing_length > 0)
	{
		size_t index = 0;

		swapped = false;
		for (index = 0; index < indexing_length; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap_int(&array[index], &array[index + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		indexing_length--;
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
