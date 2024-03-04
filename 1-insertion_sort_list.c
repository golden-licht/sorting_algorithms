#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list containing integers,
 * using insertion sort algorithm
 * @list: Pointer to pointer of the head of the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/* pointer to the second node from the start */
	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *left = current->prev;
		listint_t *tmp = left;
		bool swapped = false;

		while (left != NULL && current->n < left->n)
		{
			swapped = true;
			swap_node(current, left);
			if (current->prev == NULL)
				*list = current;
			left = current->prev;
			print_list(*list);
		}

		if (swapped)
			current = tmp->next;
		else
			current = current->next;
	}
}

/**
 * swap_node - Swaps two nodes of a listint_t list
 * @a: Pointer to the first node to be swapped
 * @b: Pointer to the second node to be swapped
*/
void swap_node(listint_t *a, listint_t *b)
{
	listint_t *tmp_next = a->next;

	a->next = b;
	b->next = tmp_next;
	a->prev = b->prev;
	b->prev = a;
	if (a->prev != NULL)
		a->prev->next = a;
	if (b->next != NULL)
		b->next->prev = b;
}
