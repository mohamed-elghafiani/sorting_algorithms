#include <stddef.h>
#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 *
 * Description: soerts a doubly linked list in ascending oreder using
 * 	the insertion sort algorithm
 * @list: the doubly linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next_node, *current_node, *current_node2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current_node = *list;
	while (current_node)
	{
		current_node2 = current_node->prev;
		while (current_node2 && current_node2->prev != NULL)
		{
			next_node = current_node2->next;
			if (next_node->n <  current_node2->n)
			{
				current_node2->next = next_node->next;
				if (next_node->next)
				{
					next_node->next->prev = current_node2;
				}
				next_node->next = current_node2;
				next_node->prev = current_node2->prev;
				current_node2->prev = next_node;
				if (next_node->prev)
				{
					next_node->prev->next = next_node;
				}
			}
			current_node2 = next_node->prev;
		}
		if (current_node2 == *list)
		{
			*list = current_node2;
		}
		current_node = current_node->next;
	}
}
