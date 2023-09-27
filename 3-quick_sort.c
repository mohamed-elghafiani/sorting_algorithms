#include <stdio.h>
#include "sort.h"

/**
 * partition - partition the array into two groups and return the pivot
 *
 * @array: an array of integers
 * @l: lower bound
 * @r: upper bound
 * Return: the pivot index or -1 on failure
 */
int partition(int *array, int l, int r)
{
	int pivot = array[r];
	int j = 0, tmp = 0, i = 0;

	if (!array || r <= l)
		return (-1);

	i = l - 1;
	for (j = l; j < r; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}

	}
	tmp = array[i + 1];
	array[i + 1] = pivot;
	array[r] = tmp;

	return (i + 1);
}

/**
 * quick_sort_alg - a function that impliments the quick sort algorithm
 *
 * @array: the array to sort
 * @l: lower bound
 * @h: higher bound
 * @size: the size of the array
 * Return: Nothing
 */

void quick_sort_alg(int *array, size_t l, size_t h, size_t size)
{
	int pivot_index;

	if (l < h)
	{
		pivot_index = partition(array, l, h);
		if (pivot_index == -1)
		{
			return;
		}
		print_array(array, size);
		quick_sort_alg(array, l, pivot_index - 1, size);
		quick_sort_alg(array, pivot_index + 1, h, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *	using the Quick sort algorithm
 *
 * @array: an array of integers
 * @size: the size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_alg(array, 0, size - 1, size);
}
