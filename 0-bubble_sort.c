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
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: An array of numbers to be sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{

	size_t step, i;

	if (array == NULL)
		return;

	for (step = 0; step < size - 1; ++step)
	{
		for (i = 0; i < size - step - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				swap_arr(array + i, array + i + 1);
				print_array(array, size);
			}
		}
	}
}
