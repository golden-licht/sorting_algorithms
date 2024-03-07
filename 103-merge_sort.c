#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */

void merge_sort(int *array, size_t size)
{
	int middle;
	size_t left_side, right_side, left, right, temp, i;
	int *temp_array = NULL;

	if (size <= 1)
		return;
	middle = size / 2;
	left_side = middle;
	right_side = size - middle;
	merge_sort(array, left_side);
	merge_sort(array + middle, right_side);
	temp_array = malloc(size * sizeof(int));
	if (temp_array == NULL)
		return;
	left = 0, right = 0, temp = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, left_side);
	printf("[right]: ");
	print_array(array + middle, right_side);
	while (left < left_side && right < right_side)
	{
		if (array[left] <= array[middle + right])
			temp_array[temp++] = array[left++];
		else
			temp_array[temp++] = array[middle + right++];
	}
	while (left < left_side)
		temp_array[temp++] = array[left++];
	while (right < right_side)
		temp_array[temp++] = array[middle + right++];
	printf("[Done]: ");
	print_array(temp_array, size);
	for (i = 0; i < size; i++)
		array[i] = temp_array[i];
	free(temp_array);
}
