#include <stddef.h>
#include "sort.h"


/**
 * selection_sort - sorts an array of integers in ascending order
 *	using the Selection sort algorithm
 *
 * @array: an array of integers
 * @size: the size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index, tmp;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (array[i] != array[min_index])
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
