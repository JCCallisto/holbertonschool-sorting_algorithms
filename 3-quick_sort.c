#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @array: The array
 * @size: Size of the array
 * @a: Index of first element
 * @b: Index of second element
 */

void swap(int *array, size_t size, int a, int b)

{
    int temp;

    if (a != b)
    {
        temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        print_array(array, size);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to partition
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot after partitioning
 */

int lomuto_partition(int *array, size_t size, int low, int high)

{
    int pivot, i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array, size, i, j);
        }
    }
    swap(array, size, i + 1, high);
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort
 * @array: The array to be sorted
 * @size: Size of the array
 * @low: Starting index
 * @high: Ending index
 */

void quick_sort_recursive(int *array, size_t size, int low, int high)

{
    int pi;

    if (low < high)
    {
        pi = lomuto_partition(array, size, low, high);
        quick_sort_recursive(array, size, low, pi - 1);
        quick_sort_recursive(array, size, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void quick_sort(int *array, size_t size)

{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, size, 0, size - 1);
}
