#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 *
 * Description: soerts a doubly linked list in ascending oreder using
 *	the insertion sort algorithm
 * @list: the doubly linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = (*list)->next;
	while (sorted != NULL)
	{
		current = sorted;
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		sorted = next;
	}
}

