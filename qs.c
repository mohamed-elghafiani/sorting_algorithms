#include <stdio.h>
#include "sort.h"

int partition(int *array, int l, int r);

void quick_sort_alg(int *array, int l, int h);

void quick_sort(int *array, size_t size);

void print_array(const int *array, size_t size);

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}

int partition(int *array, int l, int r)
{
    int pivot = array[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    int tmp = array[i + 1];
    array[i + 1] = array[r];
    array[r] = tmp;

    return (i + 1);
}

void quick_sort_alg(int *array, int l, int h)
{
    if (l < h)
    {
        int pivot_index = partition(array, l, h);
        print_array(array, h - l + 1);
        quick_sort_alg(array, l, pivot_index - 1);
        quick_sort_alg(array, pivot_index + 1, h);
    }
}

void quick_sort(int *array, size_t size)
{
    quick_sort_alg(array, 0, size - 1);
}
