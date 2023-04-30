#include "sort.h"

/**
 * swap_arr - Swap two integers in an array.
 * @num1: The first integer to swap.
 * @num2: The second integer to swap.
 */

void swap_arr(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers
 *						with last element as pivot.
 * @arr: The array.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *arr, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = arr + right;
	for (above = below = left; below < right; below++)
	{
		if (arr[below] < *pivot)
		{
			if (above < below)
			{
				swap_arr(arr + below, arr + above);
				print_array(arr, size);
			}
			above++;
		}
	}

	if (arr[above] > *pivot)
	{
		swap_arr(arr + above, pivot);
		print_array(arr, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */

void lomuto_sort(int *arr, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(arr, size, left, right);
		lomuto_sort(arr, size, left, part - 1);
		lomuto_sort(arr, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
