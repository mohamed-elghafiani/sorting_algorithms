#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - sortan array of numbers in ascending order
 *
 * @array: a list of numbers
 * @size: the size of the array @array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swap = 0, tmp;
	size_t i = 0;

	if (!array)
	{
		return;
	}
	do {
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}

	} while (swap != 0);
}
