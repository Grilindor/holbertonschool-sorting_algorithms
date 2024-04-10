#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
/**
 * swap_ints - Swap two elements of an array.
 * @a: The first element to swap.
 * @b: The second element to swap.
 */
void swap_elements(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: pointer to an array of integer
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_elements (&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
